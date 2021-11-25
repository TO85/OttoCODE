// file: {repo: EIRC2}./src/libs/eirType/QQStringList.h
#pragma once
#include "eirType.h"

#include <QStringList>

#include "QQList.h"
#include "QQSize.h"
#include "QQString.h"

#include <QtDebug>
#include <QtCore/QMetaType>

class EIRTYPE_EXPORT QQStringList : public QStringList
{
public:
    QQStringList(const int aCount, const QQString &aFillString=QQString());
    QQStringList(const QList<QString> &other);
    QQStringList(const QList<QQString> &other);
    QQStringList(const QQList<QQString> &other);
    QQStringList() = default;
    QQStringList(const QQStringList &other) = default;
    ~QQStringList() = default;
    QQStringList &operator = (const QQStringList &other) = default;

    bool notEmpty() const { return ! isEmpty(); }
    QQString first() const { return QStringList::first(); }
    QQStringList first(const int n) const;
    QQStringList reversed() const;
    QQString join(const QQString &separator) const;
    QQStringList intersected(const QQStringList &aWith) const { return intersected(it(), aWith); }
    QQStringList subSample(const int nList, const int nString);
    QStringList operator () () const { return QStringList(it()); }
    QQString operator [] (const int index) const { return at(index); }
    QQStringList operator &= (const QQStringList &aWith) const { return intersected(aWith); }

    void fill(const int aCount, const QQString &aFillString=QQString());
    void append(const QQString qqs) { QStringList::append(qqs.toQString()); }
    void append(const QQStringList &other, const int indexWidth=0);
    void prepend(const QQStringList &other);
    void intersect(const QQStringList &aWith) { it() = intersected(it(), aWith); }
    QQStringList remove(const int pos, const int num);
    QQStringList operator << (const QQString &other) { QStringList::append(other()); return it(); }
    QQStringList operator << (const QQStringList &other) { append(other); return it(); }

public: // static
    static QQStringList intersected(const QQStringList &aList, const QQStringList &aWith);

private:
    QQStringList it() const { return *this; }
    QQStringList &it() { return *this; }

public:
    QQStringList toDebugStrings(const QQSize minSize=QQSize()) const;

private:
};

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQStringList &qqsl);

Q_DECLARE_METATYPE(QQStringList);

