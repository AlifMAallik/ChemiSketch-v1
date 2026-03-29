#include "ChemistryUtils.h"
#include "ElementData.h"
#include <QMap>

ChemistryUtils *ChemistryUtils::s_instance = nullptr;

ChemistryUtils::ChemistryUtils(QObject *parent)
    : QObject(parent)
{
    s_instance = this;
}

ChemistryUtils *ChemistryUtils::instance()
{
    if (!s_instance) {
        s_instance = new ChemistryUtils();
    }
    return s_instance;
}

bool ChemistryUtils::validateMolecule(Molecule *molecule) const
{
    if (!molecule) return true;

    const ElementData *elements = ElementData::instance();
    bool allValid = true;

    // First, clear all invalid flags
    for (Bond *bond : molecule->bonds()) {
        bond->setIsInvalid(false);
    }

    // Check each atom's valence
    for (Atom *atom : molecule->atoms()) {
        double usedValence = molecule->usedValence(atom->atomId());
        int maxVal = elements->maxValence(atom->elementSymbol());

        if (usedValence > maxVal) {
            // Mark all bonds connected to this atom as invalid
            for (Bond *bond : molecule->bondsForAtom(atom->atomId())) {
                bond->setIsInvalid(true);
            }
            allValid = false;
        }
    }

    return allValid;
}

QString ChemistryUtils::classifyMolecule(Molecule *molecule) const
{
    if (!molecule || molecule->atomCount() == 0) return "empty";

    const ElementData *elements = ElementData::instance();
    bool hasMetal = false;
    bool hasMetalloid = false;
    bool hasNonMetal = false;

    for (Atom *atom : molecule->atoms()) {
        QString cat = elements->classify(atom->elementSymbol());
        if (cat == "metal")     hasMetal = true;
        else if (cat == "metalloid") hasMetalloid = true;
        else if (cat == "non_metal") hasNonMetal = true;
    }

    if (hasMetal && !hasNonMetal && !hasMetalloid)
        return "pure metal compound";
    if (hasMetal)
        return "metal-containing";
    if (hasMetalloid)
        return "metalloid-containing";
    if (hasNonMetal)
        return "purely non-metallic (likely organic)";

    return "unknown";
}

QString ChemistryUtils::molecularFormula(Molecule *molecule) const
{
    if (!molecule) return QString();

    // Count each element using Hill system: C first, H second, then alphabetical
    QMap<QString, int> counts;
    for (Atom *atom : molecule->atoms()) {
        counts[atom->elementSymbol()]++;
    }

    QString formula;
    auto appendElement = [&](const QString &sym) {
        if (counts.contains(sym)) {
            formula += sym;
            if (counts[sym] > 1)
                formula += QString::number(counts[sym]);
            counts.remove(sym);
        }
    };

    // Hill system ordering
    appendElement("C");
    appendElement("H");

    // Remaining elements alphabetically
    QStringList remaining = counts.keys();
    remaining.sort();
    for (const QString &sym : remaining) {
        formula += sym;
        if (counts[sym] > 1)
            formula += QString::number(counts[sym]);
    }

    return formula;
}

int ChemistryUtils::electronCount(Molecule *molecule) const
{
    if (!molecule) return 0;

    const ElementData *elements = ElementData::instance();
    int total = 0;
    for (Atom *atom : molecule->atoms()) {
        total += elements->atomicNumber(atom->elementSymbol());
    }
    return total;
}

double ChemistryUtils::molecularWeight(Molecule *molecule) const
{
    if (!molecule) return 0.0;

    const ElementData *elements = ElementData::instance();
    double total = 0.0;
    for (Atom *atom : molecule->atoms()) {
        total += elements->atomicWeight(atom->elementSymbol());
    }
    return total;
}

QVariantMap ChemistryUtils::moleculeInfo(Molecule *molecule) const
{
    QVariantMap info;
    if (!molecule) return info;

    info["formula"] = molecularFormula(molecule);
    info["molecularWeight"] = molecularWeight(molecule);
    info["electronCount"] = electronCount(molecule);
    info["classification"] = classifyMolecule(molecule);
    info["atomCount"] = molecule->atomCount();
    info["bondCount"] = molecule->bondCount();
    info["isValid"] = validateMolecule(molecule);

    return info;
}
