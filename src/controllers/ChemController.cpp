#include "ChemController.h"
#include "ChemistryUtils.h"
#include "FileUtils.h"
#include "BenzeneGenerator.h"
#include "ElementData.h"
#include "GeometryUtils.h"
#include <QLineF>

ChemController::ChemController(QObject *parent)
    : QObject(parent)
    , m_molecule(new Molecule(this))
{
    // NOTE: We do NOT connect moleculeChanged to canvasNeedsRepaint here.
    // tryAddBond blocks signals during mutation to prevent re-entrant
    // canvas reads. Instead, every mutation site emits canvasNeedsRepaint
    // explicitly after it is done. The only connection kept is for
    // moleculeInfoChanged so the properties panel stays live.
    connect(m_molecule, &Molecule::moleculeChanged, this, [this]() {
        m_infoDirty = true;
        emit moleculeInfoChanged();
    });
}

Molecule *ChemController::molecule() const { return m_molecule; }

QString ChemController::activeTool() const { return m_activeTool; }

void ChemController::setActiveTool(const QString &tool)
{
    if (m_activeTool != tool) {
        m_activeTool = tool;
        m_isDragging = false;
        m_startAtomId.clear();
        emit activeToolChanged();
        emit canvasNeedsRepaint();
    }
}

QString ChemController::activeElement() const { return m_activeElement; }

void ChemController::setActiveElement(const QString &element)
{
    if (!ElementData::instance()->isValidElement(element)) return;
    if (m_activeElement != element) {
        m_activeElement = element;
        emit activeElementChanged();
    }
}

bool ChemController::isDarkTheme() const { return m_isDarkTheme; }

void ChemController::setIsDarkTheme(bool dark)
{
    if (m_isDarkTheme != dark) {
        m_isDarkTheme = dark;
        emit isDarkThemeChanged();
    }
}

QVariantMap ChemController::moleculeInfo() const
{
    if (!m_molecule) return QVariantMap();
    if (m_infoDirty) {
        m_cachedInfo = ChemistryUtils::instance()->moleculeInfo(m_molecule);
        m_infoDirty = false;
    }
    return m_cachedInfo;
}

double ChemController::zoomFactor() const { return m_zoomFactor; }

void ChemController::setZoomFactor(double factor)
{
    factor = qBound(MIN_ZOOM, factor, MAX_ZOOM);
    if (!qFuzzyCompare(m_zoomFactor, factor)) {
        m_zoomFactor = factor;
        emit zoomFactorChanged();
        emit canvasNeedsRepaint();
    }
}

// --- Valence checks ---

bool ChemController::canAtomAcceptBond(const QString &atomId, double bondValence) const
{
    if (!m_molecule) return false;
    Atom *atom = m_molecule->getAtom(atomId);
    if (!atom) return false;
    double used = m_molecule->usedValence(atomId);
    int maxVal = ElementData::instance()->maxValence(atom->elementSymbol());
    return (used + bondValence) <= maxVal;
}

double ChemController::remainingValence(const QString &atomId) const
{
    if (!m_molecule) return 0.0;
    Atom *atom = m_molecule->getAtom(atomId);
    if (!atom) return 0.0;
    double used = m_molecule->usedValence(atomId);
    int maxVal = ElementData::instance()->maxValence(atom->elementSymbol());
    return qMax(0.0, maxVal - used);
}

bool ChemController::checkValenceBeforeBond(const QString &atom1Id, const QString &atom2Id,
                                             double bondValence) const
{
    if (!canAtomAcceptBond(atom1Id, bondValence)) {
        Atom *a = m_molecule->getAtom(atom1Id);
        if (a) emit const_cast<ChemController*>(this)->bondRejected(
            atom1Id, a->position().x(), a->position().y());
        return false;
    }
    if (!canAtomAcceptBond(atom2Id, bondValence)) {
        Atom *a = m_molecule->getAtom(atom2Id);
        if (a) emit const_cast<ChemController*>(this)->bondRejected(
            atom2Id, a->position().x(), a->position().y());
        return false;
    }
    return true;
}

// --- Canvas interaction ---

void ChemController::canvasPressed(const QPointF &pos)
{
    if (!m_molecule) return;

    // Clear any stale drag state
    if (m_isDragging) {
        m_isDragging = false;
        m_startAtomId.clear();
        emit canvasNeedsRepaint();
    }

    if (m_activeTool == "benzene") { addBenzeneAt(pos); return; }
    if (m_activeTool == "cyclohexane") { addCyclohexaneAt(pos); return; }
    if (m_activeTool == "cyclopentane") { addCyclopentaneAt(pos); return; }
    if (m_activeTool == "eraser") { eraseAtPoint(pos); return; }

    bool isBondTool = (m_activeTool == "single_bond" || m_activeTool == "double_bond" ||
                       m_activeTool == "triple_bond" || m_activeTool == "wedge" ||
                       m_activeTool == "hash"        || m_activeTool == "dashed" ||
                       m_activeTool == "arrow"       || m_activeTool == "aromatic");

    Atom *hitAtom = m_molecule->atomAtPoint(pos, ATOM_HIT_RADIUS);

    if (isBondTool) {
        if (hitAtom) {
            m_startAtomId = hitAtom->atomId();
            m_isDragging  = true;
            m_dragStart   = hitAtom->position();
            m_dragEnd     = pos;
        } else {
            // Place a new atom and start dragging a bond from it
            auto *newAtom = new Atom(m_activeElement, pos, 0, QString(), m_molecule);
            m_molecule->addAtom(newAtom);
            m_startAtomId = newAtom->atomId();
            m_isDragging  = true;
            m_dragStart   = pos;
            m_dragEnd     = pos;
        }
        emit canvasNeedsRepaint();
        return;
    }

    // Default: place atom at click point
    if (!hitAtom) {
        auto *newAtom = new Atom(m_activeElement, pos, 0, QString(), m_molecule);
        m_molecule->addAtom(newAtom);
        emit canvasNeedsRepaint();
    }
}

void ChemController::canvasDragged(const QPointF &pos)
{
    if (m_isDragging && m_molecule) {
        m_dragEnd = pos;
        emit canvasNeedsRepaint();
    }
}

void ChemController::canvasReleased(const QPointF &pos)
{
    // Always clear drag state — even if we return early.
    // This is the KEY guard that prevents the dashed preview
    // line from getting stuck when onCanceled fires instead
    // of onReleased (macOS trackpad fast gestures).
    const bool wasDragging = m_isDragging;
    m_isDragging = false;

    if (!wasDragging || !m_molecule) {
        m_startAtomId.clear();
        emit canvasNeedsRepaint();
        return;
    }

    Atom *startAtom = m_molecule->getAtom(m_startAtomId);
    if (!startAtom) {
        m_startAtomId.clear();
        emit canvasNeedsRepaint();
        return;
    }

    Atom *endAtom = m_molecule->atomAtPoint(pos, ATOM_HIT_RADIUS);

    // Don't bond to self
    if (endAtom && endAtom->atomId() == m_startAtomId) {
        m_startAtomId.clear();
        emit canvasNeedsRepaint();
        return;
    }

    // Upgrade existing bond if one already exists between these atoms
    if (endAtom) {
        Bond *existingBond = m_molecule->bondBetween(m_startAtomId, endAtom->atomId());
        if (existingBond) {
            Bond::BondType nextType = Bond::nextBondType(existingBond->bondType());
            Bond tempBond(QString(), QString(), nextType);
            double delta = tempBond.bondValence() - existingBond->bondValence();
            if (delta > 0) {
                double used1 = m_molecule->usedValence(m_startAtomId);
                int max1 = ElementData::instance()->maxValence(startAtom->elementSymbol());
                double used2 = m_molecule->usedValence(endAtom->atomId());
                int max2 = ElementData::instance()->maxValence(endAtom->elementSymbol());
                if ((used1 + delta) > max1) {
                    emit bondRejected(m_startAtomId, startAtom->position().x(), startAtom->position().y());
                    m_startAtomId.clear();
                    emit canvasNeedsRepaint();
                    return;
                }
                if ((used2 + delta) > max2) {
                    emit bondRejected(endAtom->atomId(), endAtom->position().x(), endAtom->position().y());
                    m_startAtomId.clear();
                    emit canvasNeedsRepaint();
                    return;
                }
            }
            existingBond->setBondType(nextType);
            validate();
            m_startAtomId.clear();
            emit canvasNeedsRepaint();
            return;
        }
    }

    // If no target atom, create one — but only if drag was long enough
    bool createdEndAtom = false;
    if (!endAtom) {
        if (QLineF(m_dragStart, pos).length() < 10.0) {
            m_startAtomId.clear();
            emit canvasNeedsRepaint();
            return;
        }
        endAtom = new Atom(m_activeElement, pos, 0, QString(), m_molecule);
        m_molecule->addAtom(endAtom);
        createdEndAtom = true;
    }

    // Resolve bond type from tool name
    QString toolName = m_activeTool;
    toolName.replace("_bond", "");
    Bond::BondType bondType = Bond::bondTypeFromString(toolName);
    double newBondValence = Bond(QString(), QString(), bondType).bondValence();

    // Valence pre-check
    if (!checkValenceBeforeBond(m_startAtomId, endAtom->atomId(), newBondValence)) {
        if (createdEndAtom) m_molecule->removeAtom(endAtom->atomId());
        m_startAtomId.clear();
        emit canvasNeedsRepaint();
        return;
    }

    auto *bond = new Bond(m_startAtomId, endAtom->atomId(), bondType, QString(), m_molecule);
    if (!tryAddBond(bond)) {
        if (createdEndAtom) m_molecule->removeAtom(endAtom->atomId());
    }

    m_startAtomId.clear();
    emit canvasNeedsRepaint();
}

// --- Tool actions ---

void ChemController::addBenzeneAt(const QPointF &center, double radius)
{
    Molecule *benzene = BenzeneGenerator::generate(center, radius, nullptr);
    if (!benzene) return;
    m_molecule->merge(benzene);
    delete benzene;
    validate();
    emit canvasNeedsRepaint();
}

void ChemController::addCyclohexaneAt(const QPointF &center, double radius)
{
    if (!m_molecule) return;
    const QVector<QPointF> pts = GeometryUtils::regularPolygon(center, radius, 6);
    QList<QString> ids;
    for (const QPointF &pt : pts) {
        auto *atom = new Atom(m_activeElement, pt, 0, QString(), m_molecule);
        m_molecule->addAtom(atom);
        ids.append(atom->atomId());
    }
    for (int i = 0; i < 6; ++i) {
        auto *bond = new Bond(ids[i], ids[(i + 1) % 6], Bond::Single, QString(), m_molecule);
        m_molecule->addBond(bond);
    }
    validate();
    emit canvasNeedsRepaint();
}

void ChemController::addCyclopentaneAt(const QPointF &center, double radius)
{
    if (!m_molecule) return;
    const QVector<QPointF> pts = GeometryUtils::regularPolygon(center, radius, 5);
    QList<QString> ids;
    for (const QPointF &pt : pts) {
        auto *atom = new Atom(m_activeElement, pt, 0, QString(), m_molecule);
        m_molecule->addAtom(atom);
        ids.append(atom->atomId());
    }
    for (int i = 0; i < 5; ++i) {
        auto *bond = new Bond(ids[i], ids[(i + 1) % 5], Bond::Single, QString(), m_molecule);
        m_molecule->addBond(bond);
    }
    validate();
    emit canvasNeedsRepaint();
}

void ChemController::changeAtomElement(const QString &atomId, const QString &newElement)
{
    if (!m_molecule) return;
    Atom *atom = m_molecule->getAtom(atomId);
    if (!atom) return;
    if (!ElementData::instance()->isValidElement(newElement)) return;
    atom->setElementSymbol(newElement);
    validate();
    emit canvasNeedsRepaint();
}

void ChemController::clearCanvas()
{
    if (!m_molecule) return;
    m_molecule->clear();
    m_isDragging = false;
    m_startAtomId.clear();
    m_infoDirty = true;
    emit canvasNeedsRepaint();
    emit moleculeInfoChanged();
}

// --- File operations ---

bool ChemController::saveToFile(const QString &filePath) const
{
    return FileUtils::instance()->saveToJson(m_molecule, filePath);
}

bool ChemController::loadFromFile(const QString &filePath)
{
    Molecule *loaded = FileUtils::instance()->loadFromJson(filePath, this);
    if (!loaded) return false;
    m_molecule->clear();
    m_molecule->merge(loaded);
    delete loaded;
    validate();
    emit canvasNeedsRepaint();
    emit moleculeInfoChanged();
    return true;
}

bool ChemController::exportMol(const QString &filePath) const
{
    return FileUtils::instance()->exportToMol(m_molecule, filePath);
}

bool ChemController::importMol(const QString &filePath)
{
    Molecule *loaded = FileUtils::instance()->importFromMol(filePath, QPointF(300, 300), this);
    if (!loaded) return false;
    m_molecule->clear();
    m_molecule->merge(loaded);
    delete loaded;
    validate();
    emit canvasNeedsRepaint();
    emit moleculeInfoChanged();
    return true;
}

// --- Zoom ---

void ChemController::zoomIn()    { setZoomFactor(m_zoomFactor * ZOOM_STEP); }
void ChemController::zoomOut()   { setZoomFactor(m_zoomFactor / ZOOM_STEP); }
void ChemController::resetZoom() { setZoomFactor(1.0); }

// --- Render data ---

QVariantList ChemController::getAtomRenderData() const
{
    QVariantList result;
    if (!m_molecule) return result;
    for (Atom *atom : m_molecule->atoms()) {
        if (!atom) continue;
        QVariantMap data;
        data["id"]          = atom->atomId();
        data["element"]     = atom->elementSymbol();
        data["x"]           = atom->position().x();
        data["y"]           = atom->position().y();
        data["charge"]      = atom->charge();
        data["highlighted"] = atom->isHighlighted();
        data["bondCount"]   = atom->bondCount();
        data["color"]       = ElementData::instance()->elementColor(atom->elementSymbol()).name();
        result.append(data);
    }
    return result;
}

QVariantList ChemController::getBondRenderData() const
{
    QVariantList result;
    if (!m_molecule) return result;
    for (Bond *bond : m_molecule->bonds()) {
        if (!bond) continue;
        Atom *a1 = m_molecule->getAtom(bond->atom1Id());
        Atom *a2 = m_molecule->getAtom(bond->atom2Id());
        if (!a1 || !a2) continue;
        QVariantMap data;
        data["id"]        = bond->bondId();
        data["x1"]        = a1->position().x();
        data["y1"]        = a1->position().y();
        data["x2"]        = a2->position().x();
        data["y2"]        = a2->position().y();
        data["type"]      = Bond::bondTypeToString(bond->bondType());
        data["isInvalid"] = bond->isInvalid();
        result.append(data);
    }
    return result;
}

QVariantMap ChemController::getTempLine() const
{
    QVariantMap data;
    data["visible"] = m_isDragging;
    if (m_isDragging) {
        data["x1"] = m_dragStart.x();
        data["y1"] = m_dragStart.y();
        data["x2"] = m_dragEnd.x();
        data["y2"] = m_dragEnd.y();
    }
    return data;
}

// --- Private helpers ---

void ChemController::eraseAtPoint(const QPointF &pos)
{
    if (!m_molecule) return;

    Atom *atom = m_molecule->atomAtPoint(pos, ATOM_HIT_RADIUS);
    if (atom) {
        m_molecule->removeAtom(atom->atomId());
        validate();
        emit canvasNeedsRepaint();
        return;
    }

    const auto bondsCopy = m_molecule->bonds();
    for (Bond *bond : bondsCopy) {
        if (!bond) continue;
        Atom *a1 = m_molecule->getAtom(bond->atom1Id());
        Atom *a2 = m_molecule->getAtom(bond->atom2Id());
        if (!a1 || !a2) continue;

        QLineF line(a1->position(), a2->position());
        QPointF d = line.p2() - line.p1();
        double lenSq = d.x() * d.x() + d.y() * d.y();
        if (lenSq < 1e-9) continue;

        double t = qBound(0.0,
            ((pos.x() - line.p1().x()) * d.x() +
             (pos.y() - line.p1().y()) * d.y()) / lenSq, 1.0);
        QPointF closest(line.p1().x() + t * d.x(), line.p1().y() + t * d.y());

        if (QLineF(pos, closest).length() < 10.0) {
            m_molecule->removeBond(bond->bondId());
            validate();
            emit canvasNeedsRepaint();
            return;
        }
    }
}

bool ChemController::tryAddBond(Bond *bond)
{
    if (!bond || !m_molecule) { delete bond; return false; }

    Atom *a1 = m_molecule->getAtom(bond->atom1Id());
    Atom *a2 = m_molecule->getAtom(bond->atom2Id());
    if (!a1 || !a2) { delete bond; return false; }

    // ── KEY FIX ──────────────────────────────────────────────────────────
    // Do NOT blockSignals here. blockSignals prevented isInvalid from being
    // set on the bond during validateMolecule(), which meant the
    // "if (!valid && bond->isInvalid())" check always saw isInvalid=false
    // and accepted every bond — OR caused the bond to be removed when it
    // shouldn't have been. Remove the blockSignals entirely and let
    // signals fire normally. The canvasNeedsRepaint from moleculeChanged
    // is harmless here — the canvas refresh() call is cheap.
    // ─────────────────────────────────────────────────────────────────────

    m_molecule->addBond(bond);

    bool valid = ChemistryUtils::instance()->validateMolecule(m_molecule);
    bool accepted = true;

    if (!valid && bond->isInvalid()) {
        // Bond caused a valence violation — remove it
        m_molecule->removeBond(bond->bondId());
        ChemistryUtils::instance()->validateMolecule(m_molecule);
        accepted = false;
    }

    m_infoDirty = true;
    emit moleculeInfoChanged();
    emit moleculeValidated(valid);
    // canvasNeedsRepaint is emitted by canvasReleased() after we return.
    // No need to emit it here — doing so would cause a double repaint.

    return accepted;
}

void ChemController::validate()
{
    if (!m_molecule) return;
    bool valid = ChemistryUtils::instance()->validateMolecule(m_molecule);
    m_infoDirty = true;
    emit moleculeValidated(valid);
    emit moleculeInfoChanged();
}