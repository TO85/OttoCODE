// file: ./libs/eirType/Milliseconds.cpp

#include "Milliseconds.h"

const QDateTime Milliseconds::csmBaseDateTime(
        QDateTime::currentDateTime());
const Milliseconds Milliseconds::csmBaseMsec(csmBaseDateTime);
const Milliseconds Milliseconds::csmZoneMsecDelta(
        (csmBaseDateTime.toUTC().toMSecsSinceEpoch())
        - csmBaseDateTime.toMSecsSinceEpoch());
const Milliseconds Milliseconds::csmNullMsec(INT64_MIN);
QString Milliseconds::smDateStampFormat("DyyyyMMdd-Thhmmss");
QString Milliseconds::smBaseDateStamp(toDateStamp(csmBaseMsec));

Milliseconds::Milliseconds(qint64 ems) : mEpochMsec(ems) {;}
Milliseconds::Milliseconds(const QDateTime & dt)
    : mEpochMsec(dt.isValid() ? dt.toMSecsSinceEpoch() : INT64_MIN) {;}
Milliseconds::Milliseconds(const QVariant &var) : mEpochMsec(var.toLongLong()) {;}

Milliseconds Milliseconds::current(void)
{
    return Milliseconds(QDateTime::currentMSecsSinceEpoch());
}

Milliseconds Milliseconds::fromIso(const QString & isoDateTime)
{
    return Milliseconds(QDateTime::fromString(isoDateTime, Qt::ISODate));
}

Milliseconds Milliseconds::fromString(const QString & dateTime)
{
    qint64 i64 = dateTime.toLongLong();
    return Milliseconds((i64 > 3000)
                           ? QDateTime::fromMSecsSinceEpoch(i64)
                           : QDateTime::fromString(dateTime, Qt::ISODate));
}

bool Milliseconds::isValid(void) const
{
    return toDateTime().isValid();
}

bool Milliseconds::isNull(void) const
{
    return csmNullMsec == mEpochMsec;
}

bool Milliseconds::isBaseNull(void) const
{
    return csmNullMsec == csmBaseMsec;
}

bool Milliseconds::isUtc(void)
{
    return 0 == csmZoneMsecDelta;
}

Milliseconds::operator qint64(void) const
{
    return mEpochMsec;;
}

Milliseconds & Milliseconds::operator += (const Milliseconds d)
{
    mEpochMsec += d;
    return *this;
}

Milliseconds & Milliseconds::operator -= (const Milliseconds d)
{
    mEpochMsec -= d;
    return *this;
}

void Milliseconds::set(const Milliseconds other)
{
    mEpochMsec = other.mEpochMsec;
}

void Milliseconds::nullify(void)
{
    mEpochMsec = csmNullMsec;
}

qint64 Milliseconds::base(void)
{
    return csmBaseMsec;
}

Milliseconds Milliseconds::null(void)
{
    return csmNullMsec;
}

QDateTime Milliseconds::baseDateTime()
{
    return csmBaseDateTime;
}

Milliseconds Milliseconds::delta(Milliseconds ems) const
{
    return Milliseconds(ems - mEpochMsec);
}

QDateTime Milliseconds::toDateTime(void) const
{
    return QDateTime::fromMSecsSinceEpoch(mEpochMsec);
}

QString Milliseconds::toString(const QString & format) const
{
    return toDateTime().toString(format.isEmpty()
                                 ? "yyyy/MM/dd hh:mm:ss.zzz"
                                 : format);
}

QString Milliseconds::toDateStamp() const
{
    return toDateStamp(mEpochMsec);
}

QString Milliseconds::baseString(const QString & format)
{
    return QDateTime::fromMSecsSinceEpoch(csmBaseMsec).toString(format);
}

QString Milliseconds::baseDateStamp()
{
    return smBaseDateStamp;
}

void Milliseconds::setDateStampFormat(const QString &format)
{
    smDateStampFormat = format;
    smBaseDateStamp = toDateStamp(csmBaseMsec);
}

QString Milliseconds::toDateStamp(const Milliseconds msec)
{
    return msec.toString(smDateStampFormat);
}

QByteArray Milliseconds::toByteArray() const
{
    return QByteArray((char *)(&mEpochMsec), sizeof (mEpochMsec));
}
