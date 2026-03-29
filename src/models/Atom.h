#ifndef ATOM_H
#define ATOM_H

#include <QObject>
#include <QPointF>
#include <QString>
#include <QUuid>
#include <QVector>
#include <QtQml/qqmlregistration.h>

class Atom : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString elementSymbol READ elementSymbol WRITE setElementSymbol NOTIFY elementSymbolChanged)
    Q_PROPERTY(QPointF position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(int charge READ charge WRITE setCharge NOTIFY chargeChanged)
    Q_PROPERTY(QString atomId READ atomId CONSTANT)
    Q_PROPERTY(bool highlighted READ isHighlighted WRITE setHighlighted NOTIFY highlightedChanged)
    Q_PROPERTY(int isotope READ isotope WRITE setIsotope NOTIFY isotopeChanged)

public:
    explicit Atom(QObject *parent = nullptr);
    Atom(const QString &element, const QPointF &pos, int charge = 0,
         const QString &id = QString(), QObject *parent = nullptr);
    ~Atom() override = default;

    QString elementSymbol() const;
    void setElementSymbol(const QString &symbol);

    QPointF position() const;
    void setPosition(const QPointF &pos);

    int charge() const;
    void setCharge(int charge);

    QString atomId() const;

    bool isHighlighted() const;
    void setHighlighted(bool highlighted);

    int isotope() const;
    void setIsotope(int isotope);

    QVector<QString> bondIds() const;
    void addBond(const QString &bondId);
    void removeBond(const QString &bondId);

    Q_INVOKABLE bool containsPoint(const QPointF &point, double radius = 20.0) const;
    Q_INVOKABLE int bondCount() const;

signals:
    void elementSymbolChanged();
    void positionChanged();
    void chargeChanged();
    void highlightedChanged();
    void isotopeChanged();

private:
    QString m_element;
    QPointF m_position;
    int m_charge = 0;
    QString m_id;
    bool m_highlighted = false;
    int m_isotope = 0;
    QVector<QString> m_bondIds;
};

#endif // ATOM_H
