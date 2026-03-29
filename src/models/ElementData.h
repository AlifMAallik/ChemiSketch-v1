#ifndef ELEMENTDATA_H
#define ELEMENTDATA_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QColor>
#include <QVector>
#include <QtQml/qqmlregistration.h>

struct ElementInfo {
    QString symbol;
    QString name;
    int atomicNumber = 0;
    double atomicWeight = 0.0;
    int maxValence = 0;
    QVector<int> commonValences;
    QColor color;
    QString category; // "metal", "metalloid", "non_metal", "noble_gas"
};

class ElementData : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit ElementData(QObject *parent = nullptr);
    ~ElementData() override = default;

    Q_INVOKABLE int maxValence(const QString &symbol) const;
    Q_INVOKABLE QVector<int> commonValences(const QString &symbol) const;
    Q_INVOKABLE QString elementName(const QString &symbol) const;
    Q_INVOKABLE int atomicNumber(const QString &symbol) const;
    Q_INVOKABLE double atomicWeight(const QString &symbol) const;
    Q_INVOKABLE QColor elementColor(const QString &symbol) const;
    Q_INVOKABLE QString classify(const QString &symbol) const;
    Q_INVOKABLE bool isValidElement(const QString &symbol) const;
    Q_INVOKABLE QStringList allSymbols() const;

    static ElementData *instance();

private:
    void initializeElements();
    QMap<QString, ElementInfo> m_elements;
    static ElementData *s_instance;
};

#endif // ELEMENTDATA_H
