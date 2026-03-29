#ifndef MOLECULE_H
#define MOLECULE_H

#include <QObject>
#include <QMap>
#include <QVariantList>
#include <QtQml/qqmlregistration.h>
#include "Atom.h"
#include "Bond.h"

class Molecule : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int atomCount READ atomCount NOTIFY moleculeChanged)
    Q_PROPERTY(int bondCount READ bondCount NOTIFY moleculeChanged)
    Q_PROPERTY(QVariantList atomList READ atomList NOTIFY moleculeChanged)
    Q_PROPERTY(QVariantList bondList READ bondList NOTIFY moleculeChanged)

public:
    explicit Molecule(QObject *parent = nullptr);
    ~Molecule() override = default;

    // Atom operations
    void addAtom(Atom *atom);
    Atom *getAtom(const QString &id) const;
    bool removeAtom(const QString &id);
    QList<Atom *> atoms() const;
    int atomCount() const;

    // Bond operations
    void addBond(Bond *bond);
    Bond *getBond(const QString &id) const;
    bool removeBond(const QString &id);
    QList<Bond *> bonds() const;
    int bondCount() const;

    // Queries
    Q_INVOKABLE Atom *atomAtPoint(const QPointF &point, double radius = 20.0) const;
    Q_INVOKABLE Bond *bondBetween(const QString &atom1Id, const QString &atom2Id) const;
    Q_INVOKABLE QList<Bond *> bondsForAtom(const QString &atomId) const;
    Q_INVOKABLE double usedValence(const QString &atomId) const;

    // Bulk operations
    Q_INVOKABLE void clear();
    void merge(Molecule *other);

    // QML-friendly lists
    QVariantList atomList() const;
    QVariantList bondList() const;

signals:
    void moleculeChanged();
    void atomAdded(Atom *atom);
    void atomRemoved(const QString &atomId);
    void bondAdded(Bond *bond);
    void bondRemoved(const QString &bondId);

private:
    QMap<QString, Atom *> m_atoms;
    QMap<QString, Bond *> m_bonds;
};

#endif // MOLECULE_H
