#ifndef CHEMISTRYUTILS_H
#define CHEMISTRYUTILS_H

#include <QObject>
#include <QString>
#include <QVariantMap>
#include <QtQml/qqmlregistration.h>
#include "Molecule.h"

class ChemistryUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit ChemistryUtils(QObject *parent = nullptr);

    // Validate all atom valencies in the molecule. Marks invalid bonds.
    // Returns true if molecule is valid (no valence violations).
    Q_INVOKABLE bool validateMolecule(Molecule *molecule) const;

    // Classify a molecule based on its atom composition.
    // Returns "organic", "metal-containing", "metalloid-containing", etc.
    Q_INVOKABLE QString classifyMolecule(Molecule *molecule) const;

    // Compute molecular formula from a Molecule object.
    Q_INVOKABLE QString molecularFormula(Molecule *molecule) const;

    // Compute total electron count (sum of atomic numbers).
    Q_INVOKABLE int electronCount(Molecule *molecule) const;

    // Compute approximate molecular weight.
    Q_INVOKABLE double molecularWeight(Molecule *molecule) const;

    // Get summary info as a QVariantMap (for display in QML info panel).
    Q_INVOKABLE QVariantMap moleculeInfo(Molecule *molecule) const;

    static ChemistryUtils *instance();

private:
    static ChemistryUtils *s_instance;
};

#endif // CHEMISTRYUTILS_H
