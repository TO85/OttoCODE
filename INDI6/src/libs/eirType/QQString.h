// file: {repo: INDI6}./src/libs/eirType/QQString.h
#pragma once
#include "eirType.h"

#include <QtCore/QByteArray>
#include <QtCore/QMetaType>
#include <QtCore/QRegularExpression>
#include <QtCore/QString>
#include <QtCore/QVariant>

#include "QQChar.h"
#include "QQList.h"
class QQStringList;

class EIRTYPE_EXPORT QQString : public QString
{
public:
    enum Flag
    {
        NoFlag      = 0,
        Simplify    = 0x00000001,
        Squeeze     = 0x00000002,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    typedef QQList<QQString> List;

public:
    QQString() = default;
    QQString(const Flags flags);
    QQString(const QString &other) : QString(other) {;}
    QQString(const QString &other, const Flags flags);
    QQString(const QString &other, const QRegularExpression validRX);
    QQString(const char *pch, const Flags flags=NoFlag);
    QQString(const char aChar, const Flags flags=NoFlag);
    QQString(const QQChar aChar, const Flags flags=NoFlag);
    QQString(const QByteArray ba, const Flags flags=NoFlag);
    QQString(const int count, const QChar c=QChar::Space, const Flags flags=NoFlag);
    QQString(const QQString &other) = default;
    ~QQString() = default;
    QQString &operator = (const QQString &other) = default;
    QQString &operator = (const QQChar aChar);

    bool notEmpty() const { return ! isEmpty(); }
    QQString string() const { return it(); }
    QQString print() const;
    QQString string(const QQString &ifEmpty) const;
    QQString left(const int n) const { return QQString(QString::left(n)); }
    QQString mid(int position, int n = -1) const { return QQString(QString::mid(position, n)); }
    QQStringList split(const QQString &sep,
                      Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
                      Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    QQStringList split(const QQChar sep,
                      Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
                      Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    QQStringList split(const int width) const;
    bool equals(const QQString &other) const;
    bool lessthan(const QQString &other) const;
    QQString squeezed() const;
    QQString appended(const QQString s, const bool delimited=true) const;
    QQString formatMessage(const QVariantList &vv) const;
    QQString formatMessage(const QVariant &v1,
                           const QVariant &v2=QVariant(),
                           const QVariant &v3=QVariant(),
                           const QVariant &v4=QVariant()) const;
    QString toQString() const { return QString(it()); }
    QString operator () () const { return toQString(); }
    bool operator == (const QQString &other) const { return equals(other); }
    bool operator <  (const QQString &other) const { return lessthan(other); }
    operator QVariant() const { return QVariant(toLocal8Bit()); }

    void set(const QString &other) { clear(); append(other); }
    void set(const QQString &other, const QRegularExpression validRX);
    QQString takeFirst();
    QQString takeFirst(const int n);
    QQChar takeFirstChar();
    QQString subSample(const int n);
    void append(const QString &other) { QString::append(other); }
    void append(const QChar qch);
    QQString operator << (const QChar qch);

public: // static
    static QQString formatMessageVars(const QQString &aFormat,
                           const QVariantList &vv);
    static QQString formatMessage4Var(const QQString &aFormat,
                           const QVariant &v1,
                           const QVariant &v2=QVariant(),
                           const QVariant &v3=QVariant(),
                           const QVariant &v4=QVariant());

private:
    void ctor(void);
    QQString it() const { return *this; }
    QQString &it() { return *this; }

private:
    Flags mFlags=NoFlag;
    static QChar smDelimiter;
};

Q_DECLARE_METATYPE(QQString);

