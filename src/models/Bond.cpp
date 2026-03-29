#include "Bond.h"

Bond::Bond(QObject *parent)
    : QObject(parent)
    , m_id(QUuid::createUuid().toString(QUuid::WithoutBraces))
{
}

Bond::Bond(const QString &atom1Id, const QString &atom2Id,
           BondType type, const QString &id, QObject *parent)
    : QObject(parent)
    , m_id(id.isEmpty() ? QUuid::createUuid().toString(QUuid::WithoutBraces) : id)
    , m_atom1Id(atom1Id)
    , m_atom2Id(atom2Id)
    , m_bondType(type)
{
}

QString Bond::bondId() const { return m_id; }
QString Bond::atom1Id() const { return m_atom1Id; }
QString Bond::atom2Id() const { return m_atom2Id; }

Bond::BondType Bond::bondType() const { return m_bondType; }

void Bond::setBondType(BondType type)
{
    if (m_bondType != type) {
        m_bondType = type;
        emit bondTypeChanged();
    }
}

bool Bond::isInvalid() const { return m_isInvalid; }

void Bond::setIsInvalid(bool invalid)
{
    if (m_isInvalid != invalid) {
        m_isInvalid = invalid;
        emit isInvalidChanged();
    }
}

double Bond::bondValence() const
{
    switch (m_bondType) {
    case Single:   return 1.0;
    case Double:   return 2.0;
    case Triple:   return 3.0;
    case Aromatic: return 1.5;
    case Wedge:    return 1.0;
    case Hash:     return 1.0;
    case Dashed:   return 1.0;
    case Arrow:    return 0.0;
    }
    return 0.0;
}

bool Bond::connectsAtom(const QString &atomId) const
{
    return m_atom1Id == atomId || m_atom2Id == atomId;
}

QString Bond::otherAtomId(const QString &atomId) const
{
    if (m_atom1Id == atomId) return m_atom2Id;
    if (m_atom2Id == atomId) return m_atom1Id;
    return QString();
}

Bond::BondType Bond::bondTypeFromString(const QString &typeStr)
{
    if (typeStr == "single")   return Single;
    if (typeStr == "double")   return Double;
    if (typeStr == "triple")   return Triple;
    if (typeStr == "wedge")    return Wedge;
    if (typeStr == "hash")     return Hash;
    if (typeStr == "dashed")   return Dashed;
    if (typeStr == "arrow")    return Arrow;
    if (typeStr == "aromatic") return Aromatic;
    return Single;
}

QString Bond::bondTypeToString(BondType type)
{
    switch (type) {
    case Single:   return "single";
    case Double:   return "double";
    case Triple:   return "triple";
    case Wedge:    return "wedge";
    case Hash:     return "hash";
    case Dashed:   return "dashed";
    case Arrow:    return "arrow";
    case Aromatic: return "aromatic";
    }
    return "single";
}

Bond::BondType Bond::nextBondType(BondType current)
{
    switch (current) {
    case Single: return Double;
    case Double: return Triple;
    case Triple: return Single;
    default:     return current;
    }
}
