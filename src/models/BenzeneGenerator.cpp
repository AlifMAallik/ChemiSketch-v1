#include "BenzeneGenerator.h"
#include "GeometryUtils.h"

Molecule *BenzeneGenerator::generate(const QPointF &center, double radius, QObject *parent)
{
    auto *mol = new Molecule(parent);

    QVector<QPointF> vertices = GeometryUtils::regularPolygon(center, radius, 6);
    QVector<Atom *> atoms;
    atoms.reserve(6);

    // Create 6 carbon atoms at hexagonal positions
    for (const QPointF &pos : vertices) {
        auto *atom = new Atom("C", pos, 0, QString(), mol);
        mol->addAtom(atom);
        atoms.append(atom);
    }

    // Create bonds: alternate double/single for Kekule structure
    for (int i = 0; i < 6; ++i) {
        int next = (i + 1) % 6;
        Bond::BondType type = (i % 2 == 0) ? Bond::Double : Bond::Single;
        auto *bond = new Bond(atoms[i]->atomId(), atoms[next]->atomId(), type,
                              QString(), mol);
        mol->addBond(bond);
    }

    return mol;
}
