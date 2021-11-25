// file: ./libs/eirType/MultiName.h
#pragma once
#include "eirType.h"

#include <QByteArray>
#include <QChar>
#include <QList>
#include <QString>
#include <QStringList>
#include <QVariant>

#include "BasicName.h"
#include "QQList.h"
#include "QQStringList.h"



class EIRTYPE_EXPORT MultiName
{
public:
    typedef QList<MultiName> List;
    typedef QMap<MultiName /*sortable*/, QVariant> Map;

public:
    explicit MultiName() = default;
    MultiName(const QString &stringNames);
    MultiName(const QQString &stringNames);
    MultiName(const char *cNames);
    MultiName(const QByteArray &baNames);
    MultiName(const BasicName segment);
    MultiName(const BasicName::List &other);
    MultiName(const QQStringList &qslNames);
    MultiName(const MultiName &base, const MultiName &name);
    MultiName(const qint64 &aNumber);
    MultiName(const MultiName &other) = default;
    ~MultiName() = default;
    MultiName &operator = (const MultiName &other) = default;

public:
    bool isEmpty() const { return mBasicSegmentNames.isEmpty(); }
    bool notEmpty() const { return  ! isEmpty(); }
    bool isValidIndex(const int ix) const;
    MultiName prepended(const MultiName &groupName) const;
    BasicName firstSegment() const;
    MultiName firstSegments(int count) const;
    BasicName segmentAt(const int index) const;
    MultiName appended(const BasicName &segment) const;
    bool startsWith(const MultiName &groupName) const;
    int segmentCount() const;
    int compare(const MultiName &other) const;
    BasicName lastSegment() const;
    MultiName segmentsMid(const int offset, const int count=-1) const;
    QQStringList toStringList(void) const;
    QQString toString(const QQString &ifEmpty=QQString()) const;
    operator QString () const;
    QQString operator () () const;
    QVariant toVariant() const;
    operator QVariant () const;
    QQString sortable() const;
    uint hash() const;
    bool operator == (const MultiName & other) const;
    bool operator <  (const MultiName & other) const;

public:
    void clear();
    void set(const QQString & qsNames);
    void set(const QQStringList & qslNames);
    void prepend(const MultiName &groupName);
    void removeFirstSegments(int count);
    void removeLastSegment();
    static QQStringList stringList(const List mnames);

public:
    static QQStringList toStringList(const List &mnl);
    static List toList(const QQStringList &qsl);
    void dump() const;

protected:
    QString join(const QChar & delimiter) const;

protected: // static
    static QChar getDelimiter();
    static void setDelimiter(const QChar & value);

private:
    BasicName::List mBasicSegmentNames;

private: // static
    static const uint scmHashSeed;
    static QChar smDelimiter;
};

Q_DECLARE_METATYPE(MultiName);
