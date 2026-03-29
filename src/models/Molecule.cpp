#include "Molecule.h"

Molecule::Molecule(QObject *parent)
    : QObject(parent)
{
}

void Molecule::addAtom(Atom *atom)
{
    if (!atom || m_atoms.contains(atom->atomId())) return;
    atom->setParent(this);
    m_atoms.insert(atom->atomId(), atom);
    emit atomAdded(atom);
    emit moleculeChanged();
}

Atom *Molecule::getAtom(const QString &id) const
{
    return m_atoms.value(id, nullptr);
}

bool Molecule::removeAtom(const QString &id)
{
    Atom *atom = m_atoms.value(id, nullptr);
    if (!atom) return false;

    // Remove all bonds connected to this atom
    const auto bondIds = atom->bondIds();
    for (const QString &bondId : bondIds) {
        removeBond(bondId);
    }

    m_atoms.remove(id);
    emit atomRemoved(id);
    emit moleculeChanged();
    atom->deleteLater();
    return true;
}

QList<Atom *> Molecule::atoms() const
{
    return m_atoms.values();
}

int Molecule::atomCount() const
{
    return m_atoms.size();
}

void Molecule::addBond(Bond *bond)
{
    if (!bond || m_bonds.contains(bond->bondId())) return;
    bond->setParent(this);
    m_bonds.insert(bond->bondId(), bond);

    // Register bond with both atoms
    Atom *a1 = getAtom(bond->atom1Id());
    Atom *a2 = getAtom(bond->atom2Id());
    if (a1) a1->addBond(bond->bondId());
    if (a2) a2->addBond(bond->bondId());

    emit bondAdded(bond);
    emit moleculeChanged();
}

Bond *Molecule::getBond(const QString &id) const
{
    return m_bonds.value(id, nullptr);
}

bool Molecule::removeBond(const QString &id)
{
    Bond *bond = m_bonds.value(id, nullptr);
    if (!bond) return false;

    // Unregister from atoms
    Atom *a1 = getAtom(bond->atom1Id());
    Atom *a2 = getAtom(bond->atom2Id());
    if (a1) a1->removeBond(id);
    if (a2) a2->removeBond(id);

    m_bonds.remove(id);
    emit bondRemoved(id);
    emit moleculeChanged();
    bond->deleteLater();
    return true;
}

QList<Bond *> Molecule::bonds() const
{
    return m_bonds.values();
}

int Molecule::bondCount() const
{
    return m_bonds.size();
}

Atom *Molecule::atomAtPoint(const QPointF &point, double radius) const
{
    for (Atom *atom : m_atoms) {
        if (atom->containsPoint(point, radius)) {
            return atom;
        }
    }
    return nullptr;
}

Bond *Molecule::bondBetween(const QString &atom1Id, const QString &atom2Id) const
{
    for (Bond *bond : m_bonds) {
        if ((bond->atom1Id() == atom1Id && bond->atom2Id() == atom2Id) ||
            (bond->atom1Id() == atom2Id && bond->atom2Id() == atom1Id)) {
            return bond;
        }
    }
    return nullptr;
}

QList<Bond *> Molecule::bondsForAtom(const QString &atomId) const
{
    QList<Bond *> result;
    for (Bond *bond : m_bonds) {
        if (bond->connectsAtom(atomId)) {
            result.append(bond);
        }
    }
    return result;
}

double Molecule::usedValence(const QString &atomId) const
{
    double total = 0.0;
    for (Bond *bond : m_bonds) {
        if (bond->connectsAtom(atomId)) {
            total += bond->bondValence();
        }
    }
    return total;
}

void Molecule::clear()
{
    const auto bondIds = m_bonds.keys();
    for (const QString &id : bondIds) {
        removeBond(id);
    }
    const auto atomIds = m_atoms.keys();
    for (const QString &id : atomIds) {
        Atom *atom = m_atoms.take(id);
        emit atomRemoved(id);
        atom->deleteLater();
    }
    emit moleculeChanged();
}

void Molecule::merge(Molecule *other)
{
    if (!other) return;

    // Reparent and transfer atoms
    for (Atom *atom : other->atoms()) {
        atom->setParent(this);
        m_atoms.insert(atom->atomId(), atom);
        emit atomAdded(atom);
    }

    // Reparent and transfer bonds
    for (Bond *bond : other->bonds()) {
        bond->setParent(this);
        m_bonds.insert(bond->bondId(), bond);
        emit bondAdded(bond);
    }

    emit moleculeChanged();
}

QVariantList Molecule::atomList() const
{
    QVariantList list;
    for (Atom *atom : m_atoms) {
        list.append(QVariant::fromValue(atom));
    }
    return list;
}

QVariantList Molecule::bondList() const
{
    QVariantList list;
    for (Bond *bond : m_bonds) {
        list.append(QVariant::fromValue(bond));
    }
    return list;
}
