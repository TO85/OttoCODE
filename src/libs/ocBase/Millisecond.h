#pragma once
#include "ocBase.h"

#include <QDateTime>
#include <QTimeZone>
#include <QString>

#include "TypeDefs.h"

class OCBASE_EXPORT Millisecond
{
public:
    Millisecond(const bool isUTC=false);
    Millisecond(const SQWORD other, const bool isUTC=false);
    void set(const bool isUTC=false);
    void set(const SQWORD msec, const bool isUTC=false);

public:
    SQWORD msec() const;
    SQWORD msecUtc() const;
    QDateTime time() const;
    QString timestamp() const;

public: // static
    static qint64 currentLocalMsec();
    static SQWORD currentUtcMsec();
    static QDateTime currentLocalTime();
    static QDateTime currentUtcTime();
    static QString currentLocalTimestamp();
    static SQWORD baseLocalMsec();
    static SQWORD baseUtcMsec();
    static QDateTime baseLocalTime();
    static QDateTime baseUtcTime();
    static QString baseLocalTimestamp();
    static QTimeZone localZone();
    static QDateTime localTime();
    static SQWORD localUtcOffset();
    static QString timestampFormat();
    static QString timestampFormat(const QString &format);

public:

private:
    SQWORD mLocalMsec=0;

private: // static
    const static QDateTime csmBaseLocalTime;
    const static QDateTime csmBaseUtcTime;
    const static SQWORD csmLocalUtcOffset;
    static QString smTimestampFormat;
};



#if 0
Milliseconds(qint64 ems);
Milliseconds(const QDateTime & dt);
Milliseconds(const QVariant &var);
bool isNull(void) const;
bool isBaseNull(void) const;
bool isValid(void) const;
operator qint64(void) const;
Milliseconds & operator += (const Milliseconds d);
Milliseconds & operator -= (const Milliseconds d);
void set(const Milliseconds other);
void nullify(void);
Milliseconds delta(Milliseconds ems=current()) const;
QDateTime toDateTime(void) const;
QString toString(const QString & format=QString()) const;
QString toDateStamp() const;
QByteArray toByteArray(void) const;

public: // static
static Milliseconds current(void);
static Milliseconds fromIso(const QString & isoDateTime);
static Milliseconds fromString(const QString & dateTime);
static bool isUtc(void);
static qint64 base(void);
static Milliseconds null(void);
static QDateTime baseDateTime();
static QString baseString(const QString & format=QString());
static QString baseDateStamp();
static void setDateStampFormat(const QString &format);
static QString toDateStamp(const Milliseconds msec);

private:
qint64 mEpochMsec;;
static const QDateTime csmBaseDateTime;
static const Milliseconds csmBaseMsec;
static const Milliseconds csmZoneMsecDelta;
static const Milliseconds csmNullMsec;
static QString smDateStampFormat;
static QString smBaseDateStamp;

#endif
