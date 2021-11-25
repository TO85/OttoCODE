// file: ./libs/eirType/Milliseconds.h
#pragma once
#include "eirType.h"

#include <QtGlobal>
#include <QtCore/QDateTime>
#include <QtCore/QMetaType>
#include <QVariant>

class EIRTYPE_EXPORT Milliseconds
{
public:
    explicit Milliseconds() = default;
    Milliseconds(const Milliseconds &other) = default;
    Milliseconds(qint64 ems);
    Milliseconds(const QDateTime & dt);
    Milliseconds(const QVariant &var);
    ~Milliseconds() = default;
    Milliseconds &operator = (const Milliseconds &other) = default;

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
};

Q_DECLARE_METATYPE(Milliseconds);
