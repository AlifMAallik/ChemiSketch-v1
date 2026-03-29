#include "FileUtils.h"
#include "GeometryUtils.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextStream>
#include <QtMath>

FileUtils *FileUtils::s_instance = nullptr;

FileUtils::FileUtils(QObject *parent)
    : QObject(parent)
{
    s_instance = this;
}

FileUtils *FileUtils::instance()
{
    if (!s_instance) {
        s_instance = new FileUtils();
    }
    return s_instance;
}

// --- JSON serialization ---

QJsonObject FileUtils::atomToJson(Atom *atom) const
{
    QJsonObject obj;
    obj["id"] = atom->atomId();
    obj["element"] = atom->elementSymbol();
    obj["x"] = atom->position().x();
    obj["y"] = atom->position().y();
    obj["charge"] = atom->charge();
    obj["isotope"] = atom->isotope();
    return obj;
}

QJsonObject FileUtils::bondToJson(Bond *bond) const
{
    QJsonObject obj;
    obj["id"] = bond->bondId();
    obj["atom1"] = bond->atom1Id();
    obj["atom2"] = bond->atom2Id();
    obj["type"] = Bond::bondTypeToString(bond->bondType());
    return obj;
}

Atom *FileUtils::atomFromJson(const QJsonObject &obj, QObject *parent) const
{
    QString id = obj["id"].toString();
    QString element = obj["element"].toString("C");
    double x = obj["x"].toDouble();
    double y = obj["y"].toDouble();
    int charge = obj["charge"].toInt(0);

    auto *atom = new Atom(element, QPointF(x, y), charge, id, parent);
    atom->setIsotope(obj["isotope"].toInt(0));
    return atom;
}

Bond *FileUtils::bondFromJson(const QJsonObject &obj, QObject *parent) const
{
    QString id = obj["id"].toString();
    QString atom1 = obj["atom1"].toString();
    QString atom2 = obj["atom2"].toString();
    Bond::BondType type = Bond::bondTypeFromString(obj["type"].toString("single"));

    return new Bond(atom1, atom2, type, id, parent);
}

bool FileUtils::saveToJson(Molecule *molecule, const QString &filePath) const
{
    if (!molecule) return false;

    QJsonObject root;

    QJsonArray atomsArray;
    for (Atom *atom : molecule->atoms()) {
        atomsArray.append(atomToJson(atom));
    }
    root["atoms"] = atomsArray;

    QJsonArray bondsArray;
    for (Bond *bond : molecule->bonds()) {
        bondsArray.append(bondToJson(bond));
    }
    root["bonds"] = bondsArray;

    QJsonDocument doc(root);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) return false;
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

Molecule *FileUtils::loadFromJson(const QString &filePath, QObject *parent) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return nullptr;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    if (doc.isNull()) return nullptr;

    QJsonObject root = doc.object();
    auto *molecule = new Molecule(parent);

    // Load atoms first
    QJsonArray atomsArray = root["atoms"].toArray();
    for (const QJsonValue &val : atomsArray) {
        Atom *atom = atomFromJson(val.toObject(), molecule);
        molecule->addAtom(atom);
    }

    // Then bonds
    QJsonArray bondsArray = root["bonds"].toArray();
    for (const QJsonValue &val : bondsArray) {
        Bond *bond = bondFromJson(val.toObject(), molecule);
        molecule->addBond(bond);
    }

    return molecule;
}

bool FileUtils::exportToMol(Molecule *molecule, const QString &filePath) const
{
    if (!molecule) return false;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream out(&file);

    // Header
    out << "ChemiSketch Molecule\n";
    out << "  ChemiSketch C++ v1.0\n";
    out << "\n";

    auto atomsList = molecule->atoms();
    auto bondsList = molecule->bonds();

    // Counts line: atoms bonds
    out << QString("%1").arg(atomsList.size(), 3)
        << QString("%1").arg(bondsList.size(), 3)
        << "  0  0  0  0  0  0  0  0  V2000\n";

    // Build atom index map
    QMap<QString, int> atomIndex;
    int idx = 1;
    for (Atom *atom : atomsList) {
        atomIndex[atom->atomId()] = idx++;
    }

    // Atom block
    for (Atom *atom : atomsList) {
        out << QString("%1").arg(atom->position().x(), 10, 'f', 4)
            << QString("%1").arg(atom->position().y(), 10, 'f', 4)
            << QString("%1").arg(0.0, 10, 'f', 4)  // z
            << " " << atom->elementSymbol().leftJustified(3)
            << " 0  0  0  0  0  0  0  0  0  0  0  0\n";
    }

    // Bond block
    for (Bond *bond : bondsList) {
        int a1 = atomIndex.value(bond->atom1Id(), 0);
        int a2 = atomIndex.value(bond->atom2Id(), 0);
        int type = 1;
        switch (bond->bondType()) {
        case Bond::Single:   type = 1; break;
        case Bond::Double:   type = 2; break;
        case Bond::Triple:   type = 3; break;
        case Bond::Aromatic: type = 4; break;
        case Bond::Wedge:    type = 1; break; // stereo handled separately in real MOL
        case Bond::Hash:     type = 1; break;
        case Bond::Dashed:   type = 1; break;
        case Bond::Arrow:    type = 0; break;
        }
        out << QString("%1").arg(a1, 3)
            << QString("%1").arg(a2, 3)
            << QString("%1").arg(type, 3)
            << "  0  0  0  0\n";
    }

    out << "M  END\n";
    file.close();
    return true;
}

Molecule *FileUtils::importFromMol(const QString &filePath, const QPointF &center,
                                    QObject *parent) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return nullptr;

    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    if (lines.size() < 4) return nullptr;

    // Parse counts line (line index 3)
    QString countsLine = lines[3].trimmed();
    QStringList countParts = countsLine.split(QRegularExpression("\\s+"));
    if (countParts.size() < 2) return nullptr;

    int numAtoms = countParts[0].toInt();
    int numBonds = countParts[1].toInt();

    if (lines.size() < 4 + numAtoms + numBonds) return nullptr;

    auto *molecule = new Molecule(parent);

    // Arrange atoms in a circle if MOL coords are all zero or missing,
    // otherwise use actual coordinates
    QVector<Atom *> atomList;
    bool hasCoords = false;

    for (int i = 0; i < numAtoms; ++i) {
        QString line = lines[4 + i];
        QStringList parts = line.trimmed().split(QRegularExpression("\\s+"));
        if (parts.size() < 4) continue;

        double x = parts[0].toDouble();
        double y = parts[1].toDouble();
        QString element = parts[3].trimmed();

        if (std::abs(x) > 0.001 || std::abs(y) > 0.001) {
            hasCoords = true;
        }

        auto *atom = new Atom(element, QPointF(x, y), 0, QString(), molecule);
        molecule->addAtom(atom);
        atomList.append(atom);
    }

    // If no real coordinates, generate circular layout
    if (!hasCoords && numAtoms > 0) {
        double radius = 50.0;
        double angleStep = 360.0 / numAtoms;
        for (int i = 0; i < numAtoms; ++i) {
            double angle = qDegreesToRadians(angleStep * i - 90.0);
            double x = center.x() + radius * std::cos(angle);
            double y = center.y() + radius * std::sin(angle);
            atomList[i]->setPosition(QPointF(x, y));
        }
    } else {
        // Scale and center the coordinates
        double minX = 1e9, minY = 1e9, maxX = -1e9, maxY = -1e9;
        for (Atom *atom : atomList) {
            minX = qMin(minX, atom->position().x());
            minY = qMin(minY, atom->position().y());
            maxX = qMax(maxX, atom->position().x());
            maxY = qMax(maxY, atom->position().y());
        }
        double scale = 50.0;
        double cx = (minX + maxX) / 2.0;
        double cy = (minY + maxY) / 2.0;
        for (Atom *atom : atomList) {
            double x = center.x() + (atom->position().x() - cx) * scale;
            double y = center.y() + (atom->position().y() - cy) * scale;
            atom->setPosition(QPointF(x, y));
        }
    }

    // Parse bonds
    for (int i = 0; i < numBonds; ++i) {
        QString line = lines[4 + numAtoms + i];
        QStringList parts = line.trimmed().split(QRegularExpression("\\s+"));
        if (parts.size() < 3) continue;

        int a1Idx = parts[0].toInt() - 1; // 1-based to 0-based
        int a2Idx = parts[1].toInt() - 1;
        int typeInt = parts[2].toInt();

        if (a1Idx < 0 || a1Idx >= numAtoms || a2Idx < 0 || a2Idx >= numAtoms) continue;

        Bond::BondType bondType = Bond::Single;
        switch (typeInt) {
        case 1: bondType = Bond::Single;   break;
        case 2: bondType = Bond::Double;   break;
        case 3: bondType = Bond::Triple;   break;
        case 4: bondType = Bond::Aromatic; break;
        default: bondType = Bond::Single;  break;
        }

        auto *bond = new Bond(atomList[a1Idx]->atomId(), atomList[a2Idx]->atomId(),
                              bondType, QString(), molecule);
        molecule->addBond(bond);
    }

    return molecule;
}
