#ifndef BOND_H
#define BOND_H

#include <QObject>
#include <QString>
#include <QUuid>
#include <QtQml/qqmlregistration.h>

class Bond : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString bondId READ bondId CONSTANT)
    Q_PROPERTY(QString atom1Id READ atom1Id CONSTANT)
    Q_PROPERTY(QString atom2Id READ atom2Id CONSTANT)
    Q_PROPERTY(BondType bondType READ bondType WRITE setBondType NOTIFY bondTypeChanged)
    Q_PROPERTY(bool isInvalid READ isInvalid WRITE setIsInvalid NOTIFY isInvalidChanged)

public:
    enum BondType {
        Single,
        Double,
        Triple,
        Wedge,
        Hash,
        Dashed,
        Arrow,
        Aromatic
    };
    Q_ENUM(BondType)

    explicit Bond(QObject *parent = nullptr);
    Bond(const QString &atom1Id, const QString &atom2Id,
         BondType type = Single, const QString &id = QString(),
         QObject *parent = nullptr);
    ~Bond() override = default;

    QString bondId() const;
    QString atom1Id() const;
    QString atom2Id() const;

    BondType bondType() const;
    void setBondType(BondType type);

    bool isInvalid() const;
    void setIsInvalid(bool invalid);

    Q_INVOKABLE double bondValence() const;
    Q_INVOKABLE bool connectsAtom(const QString &atomId) const;
    Q_INVOKABLE QString otherAtomId(const QString &atomId) const;

    static BondType bondTypeFromString(const QString &typeStr);
    static QString bondTypeToString(BondType type);
    static BondType nextBondType(BondType current);

signals:
    void bondTypeChanged();
    void isInvalidChanged();

private:
    QString m_id;
    QString m_atom1Id;
    QString m_atom2Id;
    BondType m_bondType = Single;
    bool m_isInvalid = false;
};

#endif // BOND_H
