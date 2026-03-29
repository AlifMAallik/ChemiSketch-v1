#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QtQml/qqmlregistration.h>
#include "Molecule.h"

class FileUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit FileUtils(QObject *parent = nullptr);

    // Save molecule to JSON format.
    Q_INVOKABLE bool saveToJson(Molecule *molecule, const QString &filePath) const;

    // Load molecule from JSON format. Caller takes ownership.
    Q_INVOKABLE Molecule *loadFromJson(const QString &filePath, QObject *parent = nullptr) const;

    // Export molecule to a simple MOL-like text format.
    Q_INVOKABLE bool exportToMol(Molecule *molecule, const QString &filePath) const;

    // Import from simplified MOL text format.
    Q_INVOKABLE Molecule *importFromMol(const QString &filePath, const QPointF &center = QPointF(300, 300),
                                         QObject *parent = nullptr) const;

    static FileUtils *instance();

private:
    QJsonObject atomToJson(Atom *atom) const;
    QJsonObject bondToJson(Bond *bond) const;
    Atom *atomFromJson(const QJsonObject &obj, QObject *parent) const;
    Bond *bondFromJson(const QJsonObject &obj, QObject *parent) const;

    static FileUtils *s_instance;
};

#endif // FILEUTILS_H
