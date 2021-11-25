#include "Uid.h"

#include <QDateTime>
#include <QHostInfo>

#include <eirXfr/Debug.h>

Uid Uid::smSeedUuid = QUuid::createUuid();
QString Uid::smSeedString = QString("%1:%2@%3").arg("urn",
            QHostInfo::localHostName(), QHostInfo::localDomainName());
QUuid Uid::smNameSpace = QUuid::createUuidV3(smSeedUuid, smSeedString);

UInt128 Uid::toU128() const
{
    QString hex128 = mUuid.toString(QUuid::Id128);
    quint64 up64 = hex128.left(128).toULongLong();
    quint64 lo64 = hex128.mid(128).toULongLong();
    return UInt128(up64, lo64);
}

QDebug operator << (QDebug dbg, const Uid u)
{
    dbg << u.trace(); return dbg;
}
