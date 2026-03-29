#ifndef CHEMCONTROLLER_H
#define CHEMCONTROLLER_H

#include <QObject>
#include <QPointF>
#include <QString>
#include <QVariantMap>
#include <QVariantList>
#include <QtQml/qqmlregistration.h>
#include "Molecule.h"
#include "Bond.h"

class ChemController : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(Molecule *molecule READ molecule CONSTANT)
    Q_PROPERTY(QString activeTool READ activeTool WRITE setActiveTool NOTIFY activeToolChanged)
    Q_PROPERTY(QString activeElement READ activeElement WRITE setActiveElement NOTIFY activeElementChanged)
    Q_PROPERTY(bool isDarkTheme READ isDarkTheme WRITE setIsDarkTheme NOTIFY isDarkThemeChanged)
    Q_PROPERTY(QVariantMap moleculeInfo READ moleculeInfo NOTIFY moleculeInfoChanged)
    Q_PROPERTY(double zoomFactor READ zoomFactor WRITE setZoomFactor NOTIFY zoomFactorChanged)

public:
    explicit ChemController(QObject *parent = nullptr);
    ~ChemController() override = default;

    Molecule *molecule() const;

    QString activeTool() const;
    void setActiveTool(const QString &tool);

    QString activeElement() const;
    Q_INVOKABLE void setActiveElement(const QString &element);

    bool isDarkTheme() const;
    void setIsDarkTheme(bool dark);

    QVariantMap moleculeInfo() const;

    double zoomFactor() const;
    void setZoomFactor(double factor);

    // --- Canvas interaction methods (called from QML) ---

    Q_INVOKABLE void canvasPressed(const QPointF &pos);
    Q_INVOKABLE void canvasDragged(const QPointF &pos);
    Q_INVOKABLE void canvasReleased(const QPointF &pos);

    // --- Bond validation (callable from QML BondValidator) ---

    // Check if adding a bond of the given valence to atomId would exceed max valence.
    Q_INVOKABLE bool canAtomAcceptBond(const QString &atomId, double bondValence) const;

    // Get remaining valence capacity for an atom.
    Q_INVOKABLE double remainingValence(const QString &atomId) const;

    // --- Tool actions ---

    Q_INVOKABLE void addBenzeneAt(const QPointF &center, double radius = 50.0);
    Q_INVOKABLE void addCyclohexaneAt(const QPointF &center, double radius = 50.0);
    Q_INVOKABLE void addCyclopentaneAt(const QPointF &center, double radius = 45.0);
    Q_INVOKABLE void changeAtomElement(const QString &atomId, const QString &newElement);
    Q_INVOKABLE void clearCanvas();

    // --- File operations ---
    Q_INVOKABLE bool saveToFile(const QString &filePath) const;
    Q_INVOKABLE bool loadFromFile(const QString &filePath);
    Q_INVOKABLE bool exportMol(const QString &filePath) const;
    Q_INVOKABLE bool importMol(const QString &filePath);

    // --- Zoom ---
    Q_INVOKABLE void zoomIn();
    Q_INVOKABLE void zoomOut();
    Q_INVOKABLE void resetZoom();

    // --- Data for QML rendering ---

    Q_INVOKABLE QVariantList getAtomRenderData() const;
    Q_INVOKABLE QVariantList getBondRenderData() const;
    Q_INVOKABLE QVariantMap getTempLine() const;

signals:
    void activeToolChanged();
    void activeElementChanged();
    void isDarkThemeChanged();
    void moleculeInfoChanged();
    void zoomFactorChanged();
    void canvasNeedsRepaint();
    void moleculeValidated(bool isValid);

    // Emitted when a bond is rejected due to valence limits.
    // QML can use this to flash the atom red.
    void bondRejected(const QString &atomId, double x, double y);

private:
    void eraseAtPoint(const QPointF &pos);
    bool tryAddBond(Bond *bond);
    void validate();

    // Check valence before creating a bond. Returns false if either atom
    // would exceed its max valence.
    bool checkValenceBeforeBond(const QString &atom1Id, const QString &atom2Id,
                                double bondValence) const;

    Molecule *m_molecule = nullptr;
    QString m_activeTool = "single_bond";
    QString m_activeElement = "C";
    bool m_isDarkTheme = true;
    double m_zoomFactor = 1.0;

    // Bond drawing state
    QString m_startAtomId;
    bool m_isDragging = false;
    QPointF m_dragStart;
    QPointF m_dragEnd;

    // Cache moleculeInfo to avoid recomputing during signals
    mutable QVariantMap m_cachedInfo;
    mutable bool m_infoDirty = true;

    static constexpr double MIN_ZOOM = 0.2;
    static constexpr double MAX_ZOOM = 5.0;
    static constexpr double ZOOM_STEP = 1.15;
    static constexpr double ATOM_HIT_RADIUS = 20.0;
    static constexpr double BOND_END_HIT_RADIUS = 30.0;
};

#endif // CHEMCONTROLLER_H
