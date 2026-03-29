#include "Atom.h"
#include <cmath>

Atom::Atom(QObject *parent)
    : QObject(parent)
    , m_element("C")
    , m_position(0, 0)
    , m_id(QUuid::createUuid().toString(QUuid::WithoutBraces))
{
}

Atom::Atom(const QString &element, const QPointF &pos, int charge,
           const QString &id, QObject *parent)
    : QObject(parent)
    , m_element(element)
    , m_position(pos)
    , m_charge(charge)
    , m_id(id.isEmpty() ? QUuid::createUuid().toString(QUuid::WithoutBraces) : id)
{
}

QString Atom::elementSymbol() const { return m_element; }

void Atom::setElementSymbol(const QString &symbol)
{
    if (m_element != symbol) {
        m_element = symbol;
        emit elementSymbolChanged();
    }
}

QPointF Atom::position() const { return m_position; }

void Atom::setPosition(const QPointF &pos)
{
    if (m_position != pos) {
        m_position = pos;
        emit positionChanged();
    }
}

int Atom::charge() const { return m_charge; }

void Atom::setCharge(int charge)
{
    if (m_charge != charge) {
        m_charge = charge;
        emit chargeChanged();
    }
}

QString Atom::atomId() const { return m_id; }

bool Atom::isHighlighted() const { return m_highlighted; }

void Atom::setHighlighted(bool highlighted)
{
    if (m_highlighted != highlighted) {
        m_highlighted = highlighted;
        emit highlightedChanged();
    }
}

int Atom::isotope() const { return m_isotope; }

void Atom::setIsotope(int isotope)
{
    if (m_isotope != isotope) {
        m_isotope = isotope;
        emit isotopeChanged();
    }
}

QVector<QString> Atom::bondIds() const { return m_bondIds; }

void Atom::addBond(const QString &bondId)
{
    if (!m_bondIds.contains(bondId)) {
        m_bondIds.append(bondId);
    }
}

void Atom::removeBond(const QString &bondId)
{
    m_bondIds.removeAll(bondId);
}

bool Atom::containsPoint(const QPointF &point, double radius) const
{
    double dx = point.x() - m_position.x();
    double dy = point.y() - m_position.y();
    return (dx * dx + dy * dy) <= (radius * radius);
}

int Atom::bondCount() const
{
    return m_bondIds.size();
}
