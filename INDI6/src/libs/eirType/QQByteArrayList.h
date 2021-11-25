#pragma once
#include "eirType.h"

#include <QtCore/QByteArray>
#include <QtCore/QByteArrayList>

#include <QtCore/QMetaType>

#include "QQByteArray.h"
#include "QQList.h"
#include "QQString.h"

class EIRTYPE_EXPORT QQByteArrayList : public QByteArrayList
{
public:
    QQByteArrayList(const QList<QByteArray> &other) { set(other); }
    explicit QQByteArrayList() = default;
    QQByteArrayList(const QQByteArrayList &other) = default;
    ~QQByteArrayList() = default;
    QQByteArrayList &operator = (const QQByteArrayList &other) = default;

public:
    QQByteArray join(const char aSeparator) { return QByteArrayList::join(aSeparator); }

public:
    void set(const QList<QByteArray> &other);
};


Q_DECLARE_METATYPE(QQByteArrayList);
