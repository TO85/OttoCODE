#pragma once
#include "ocqCore.h"

#include <QList>
#include "QQString.h"

#include <QStringList>
#include <QMetaType>

class OCQCORE_EXPORT QQStringList : public QStringList
{
public:
    QQStringList(const QQString & first);
    QQStringList(const QList<QString> other);
    QQStringList(const int size, const QQString &fill=QQString());

public:
//    QQString join(const QQString & delims);
  //  QQString join(const QChar & delim);

public: // QMetaType
    QQStringList() = default;
    QQStringList(const QQStringList &other) = default;
    ~QQStringList() = default;
    QQStringList &operator = (const QQStringList &other) = default;
};

Q_DECLARE_METATYPE(QQStringList);

