#ifndef BENZENEGENERATOR_H
#define BENZENEGENERATOR_H

#include <QPointF>
#include "Molecule.h"

class BenzeneGenerator {
public:
    // Generate a benzene molecule centered at the given point.
    // Alternates single/double bonds in Kekule form.
    // Caller takes ownership of the returned Molecule.
    static Molecule *generate(const QPointF &center, double radius = 50.0,
                              QObject *parent = nullptr);
};

#endif // BENZENEGENERATOR_H
