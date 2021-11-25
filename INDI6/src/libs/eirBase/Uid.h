#pragma once
#include "eirBase.h"

#include <QtDebug>
#include <QtCore/QHash>
#include <QtCore/QQueue>
#include <QtCore/QString>
#include <QtCore/QUuid>
#include <QtCore/QVariant>

#include "UInt128.h"

class EIRBASE_EXPORT Uid
{
public:
    typedef QList<Uid> List;
    typedef QQueue<Uid> Queue;
    typedef QHash<Uid, QVariant> Hash;

public:
    Uid(const bool create=false) : mUuid(create ? QUuid::createUuid() : QUuid()) {;}
    Uid(const QString &data) : mUuid(create(data)) {;}
    Uid(const Uid &other)  : mUuid(other) {;}
    Uid(const QUuid &other) : mUuid(other) {;}
    Uid operator =(const Uid &other) { set(other.toUuid()); return mUuid; }

public: // status
    bool isNull() const { return mUuid.isNull(); }
    QByteArray toByteArray(void) const;
    QString toString(void) const { return mUuid.toString(); }
    UInt128 toU128(void) const;
    QString trace() const { return mUuid.toString(QUuid::WithBraces).right(14); }
    QString tail() const { return trace(); }
    bool operator < (const Uid &other) const { return toU128() <  other.toU128(); }
    bool operator ==(const Uid &other) const { return toU128() == other.toU128(); }
    QUuid toUuid() const { return mUuid; }
    operator QUuid () const { return toUuid(); }

public: // commands
    void set(const QUuid &other) { mUuid.fromString(other.toString()); }
    void nullify() { set(QUuid()); }

public: // static
    static Uid create(const QString &data)
    { return QUuid::createUuidV3(smNameSpace, data); }

    static Uid nsSeed() { return smSeedUuid; }
    static QString &nsString() { return smSeedString; }
    static Uid nsUuid() { return smNameSpace; }
    static void setSeed(const Uid id, const QString &data)
    { smSeedUuid = id, smSeedString = data, smNameSpace = QUuid::createUuidV3(id, data); }
    static void setNameSpace(const Uid id)
    { smSeedUuid = QUuid(), smSeedString.clear(), smNameSpace = id; }
    static void setNameSpace(const QString &data)
    { smSeedString = data, smNameSpace = QUuid::createUuidV3(smSeedUuid, data); }

private:
    QUuid mUuid;
    static Uid smSeedUuid;
    static QString smSeedString;
    static QUuid smNameSpace;
};

extern EIRBASE_EXPORT QDebug operator << (QDebug dbg, const Uid u);


