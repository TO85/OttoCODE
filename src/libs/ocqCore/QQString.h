#pragma once
#include "ocqCore.h"

#include <QString>

#include <QMetaType>
#include <QStringList>
#include <QVariant>

class OCQCORE_EXPORT QQString : public QString
{
public:
    QQString(const QString &other) : QString(other) {;}
    QQString(const char *psz) : QString(psz) {;}

public:
    bool notNull() const { return ! QString::isNull(); }
    bool notEmpty() const { return ! QString::isEmpty(); }
    QStringList split(const QChar &separator=sectionDelimiter()) const;
    int sectionCount() const;
    QQString firstSection() const;
    QQString firstSections(const int n) const;
    QQString lastSection() const;
    QQString lastSections(const int n) const;
    QStringList sectionList() const;
    bool equal(const QQString &other) const;
    bool less(const QQString &other) const;
    bool operator == (const QQString &other) const { return equal(other); }
    bool operator <  (const QQString &other) const { return less(other); }
    QQString replaced(QChar before, QChar after) const;
    QQString formatMessage(const QVariantList &vv) const;
    QQString formatMessage(const QVariant &v1,
                           const QVariant &v2=QVariant(),
                           const QVariant &v3=QVariant(),
                           const QVariant &v4=QVariant()) const;

public:

protected:
    QQString(const QChar & sectionDelimiter, const SectionFlags sectionFlags, const QString & other);

private:
    QString qstring() const { return *this; }
    QString & qstring() { return *this; }
    QQString it() const { return *this; }
    QQString & it() { return *this; }

public: // static
    static QQString formatMessageVars(const QQString &aFormat,
                           const QVariantList &vv);
    static QQString formatMessage4Var(const QQString &aFormat,
                           const QVariant &v1,
                           const QVariant &v2=QVariant(),
                           const QVariant &v3=QVariant(),
                           const QVariant &v4=QVariant());

protected: // static
    static QChar sectionDelimiter();
    static QChar sectionDelimiter(const QChar &delimiter);
    static SectionFlags sectionFlags();
    static SectionFlags sectionFlags(const SectionFlags &flags);

private: // static
    static QChar smSectionDelimiter;
    static SectionFlags smSectionFlags;

public: // QMetaType
    QQString() = default;
    QQString(const QQString &other) = default;
    ~QQString() = default;
    QQString &operator = (const QQString &other) = default;
};

Q_DECLARE_METATYPE(QQString);

#if 0
#include <QtCore/QByteArray>
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
    QQString(const Flags flags);
    QQString(const QString &other, const Flags flags);
    QQString(const char *pch, const char *disambigulation);
    QQString(const QString &other, const QRegularExpression validRX);
    QQString(const char *pch, const Flags flags=NoFlag);
    QQString(const char aChar, const Flags flags=NoFlag);
    QQString(const QQChar aChar, const Flags flags=NoFlag);
    QQString(const QByteArray ba, const Flags flags=NoFlag);
    QQString(const int count, const QChar c=QChar::Space, const Flags flags=NoFlag);
    QQString(const char *pchFormat, const QVariant &v1, const QVariant &v2=QVariant(),
             const QVariant &v3=QVariant(), const QVariant &v4=QVariant());
    QQString &operator = (const QQChar aChar);

    bool notEmpty() const { return ! isEmpty(); }
    QQString string() const { return it(); }
    QQString print() const;
    QQString string(const QQString &ifEmpty) const;
    QQString left(const int n) const { return QQString(QString::left(n)); }
    QQString mid(int position, int n = -1) const { return QQString(QString::mid(position, n)); }
    QQStringList split(const QQString &sep,
                      Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
                      Qt::CaseSensitivity cs = Qt::CaseSensitive,
                      const Flags flags=NoFlag) const;
#if 0
    QQStringList split(const QQChar sep,
                      Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
                      Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
#endif
    QQStringList split(const int width) const;
    bool equals(const QQString &other) const;
    bool lessthan(const QQString &other) const;
    QQString squeezed() const;
    QQString appended(const QQString s, const bool delimited=true) const;
    QString toQString() const { return QString(it()); }
    QString operator () () const { return toQString(); }
    bool operator == (const QQString &other) const { return equals(other); }
    bool operator <  (const QQString &other) const { return lessthan(other); }
    operator QVariant() const { return QVariant(toLocal8Bit()); }

    void set(const QString &other) { clear(); append(other); }
    void set(const QQString &other, const QRegularExpression validRX);
    void set(const QQString &format, const QVariant &v1, const QVariant &v2=QVariant(),
             const QVariant &v3=QVariant(), const QVariant &v4=QVariant());
    QQString takeFirst();
    QQString takeFirst(const int n);
    QQChar takeFirstChar();
    void makeUpper();
    QQString subSample(const int n);
    void append(const QString &other) { QString::append(other); }
    void append(const QChar qch);
    QQString operator << (const QChar qch);


private:
    void ctor(void);
    QQString it() const { return *this; }
    QQString &it() { return *this; }

private:
    Flags mFlags=NoFlag;
    static QChar smDelimiter;
};

#endif
