#pragma once
#include "eirType.h"

#include <list>
#include "QQString.h"

#include "QQStringList.h"

class EIRTYPE_EXPORT QQStringStdList : public std::list<QQString>
{
public:
    QQStringStdList();
    QQStringStdList & operator = (const QQStringList &other);
    QQString takeFirst();
    virtual void clear();
    void append(const QQString &entry);
    void prepend(const QQStringList &other);
    bool removeOne(const QQString &entry);
    QQStringList toStringList() const;
    QString toDebugString() const;
};

EIRTYPE_EXPORT QDebug operator<<(QDebug dbg, const QQStringStdList &list);
