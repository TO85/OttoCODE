//! \file BasicName.h
#pragma once
#include "eirType.h"

#include <QtCore/QByteArray>
#include <QtCore/QChar>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QRegularExpression>
#include <QtCore/QString>

#include "QQByteArray.h"
#include "QQList.h"
class QQString;
class QQStringList;

class EIRTYPE_EXPORT BasicName
{
public:
    typedef QQByteArray Sortable;
    typedef QQList<BasicName> List;
    typedef QMap<BasicName, QQString> StringMap;
public:
    explicit BasicName() = default;
    BasicName(const QString & sname) { set(sname); }
    BasicName(const QQString & sname);
    BasicName(const char * cName);
    BasicName(const QByteArray & baName);
    BasicName(const BasicName &other) = default;
    ~BasicName() = default;
    BasicName &operator = (const BasicName &other) = default;

    bool isEmpty() const;
    bool notEmpty() const;
    QByteArray toByteArray() const;
    QQString toString() const;
    operator QQString () const;
    QString operator () () const;
    Sortable sortable() const;
    bool operator == (const BasicName & other) const;
    bool operator != (const BasicName & other) const;
    bool operator <  (const BasicName & other) const;

public:
    void clear() { mName.clear(); }
    void set(QQString name);

public: // static
    static QQStringList toStringList(BasicName::List basicList);
    static BasicName::List listFrom(QQString &names);
    static BasicName::List listFrom(const QQStringList &names);

private: // static
    static bool isValidFirstChar(const QChar &sChar);
    static bool isValidChar(const QChar &sChar);

public:
    bool UnitTest(void);

protected: // static
    static QRegularExpression smListFromStringSeperatorRx;
    static QRegularExpression smValidFirstCharRx;
    static QRegularExpression smValidCharRx;
    static QChar smInvalidReplaceChar;

private:
    QQString mName;
};

Q_DECLARE_METATYPE(BasicName);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const BasicName &bn);

