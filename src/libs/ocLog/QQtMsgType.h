#pragma once
#include "eirType.h"

#include <QtDebug>
#include <QtCore/QMetaType>

#include "QQString.h"

class EIRTYPE_EXPORT QQtMsgType
{
public:
    enum Severity
    {
        $null       = 0,
        Trace       = 0x0010,
        Info        = 0x0020,
        Warn        = 0x0040,
        Error       = 0x0080,
        Assert      = 0x0100,
        $past       = Assert << 1
    };

public:
    explicit QQtMsgType() = default;
    QQtMsgType(const QtMsgType other) : mMsgType(other) {;}
    QQtMsgType(const QQtMsgType &other) = default;
    ~QQtMsgType() = default;
    QQtMsgType &operator = (const QQtMsgType &other) = default;

    QtMsgType value() const { return mMsgType; }
    QtMsgType operator () () const { return value(); }

    bool isNull() const { return $null == severity(it()); }
    bool notNull() const { return ! isNull(); }
    bool isValid() const;
    bool isUser() const { return notNull() && Info == severity(it()); }
    bool isDebug() const { return notNull() && Info != severity(it()); }
    bool eqInfo() const { return notNull() && Info == severity(it()); }
    bool eqWarn() const { return notNull() && Warn == severity(it()); }
    bool eqError() const { return notNull() && Error == severity(it()); }
    bool eqAssert() const { return notNull() && Assert == severity(it()); }
    bool isWarning() const { return notNull() &&  severity(it()) >= Warn; }
    bool isError() const { return notNull() &&  severity(it()) >= Error; }
    bool notError() const { return ! isError(); }
    bool isFatal() const { return notNull() &&  severity(it()) >= Assert; }
    bool greater(const QQtMsgType other);
    bool operator > (const QQtMsgType other) { return greater(other); }
    Severity severity() const { return severity(it()); }
    QQChar prefix() const { return prefix(it()); }
    QQString name() const { return name(it()); }
    QQString severityName() const { return severityName(it()); }

public: // setters
    void clear() { mMsgType = QtMsgType(-2); }
    void setError() { mMsgType = QtCriticalMsg; }
    void set(const QtMsgType aQMT) { mMsgType = aQMT; }

public: // static
    static Severity severity(const QQtMsgType aQMT);
    static QQString severityName(const QQtMsgType aQMT);
    static QQChar prefix(const QQtMsgType aQMT);
    static QQString name(const QQtMsgType aQMT);

public: // debug
    QQString toInfoString() const;
    QQString toDebugString() const;

private:
    QQtMsgType &it() { return *this; }
    QQtMsgType it() const { return *this; }

private:
    QtMsgType mMsgType=QtMsgType(-1);
};

Q_DECLARE_METATYPE(QQtMsgType);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQtMsgType mt);
