#pragma once
#include "eirType.h"

#include <QtCore/QByteArray>

#include <QtCore/QMetaType>

#include "QQList.h"
#include "QQString.h"

class EIRTYPE_EXPORT QQByteArray : public QByteArray
{
public:
    typedef QQList<QQByteArray> List;

public:
    QQByteArray(const QByteArray &other) : QByteArray(other) {;}
    QQByteArray(const quint64 aU64);
    explicit QQByteArray() = default;
    QQByteArray(const QQByteArray &other) = default;
    ~QQByteArray() = default;
    QQByteArray &operator = (const QQByteArray &other) = default;

public:
    bool notEmpty() const { return ! isEmpty(); }
    QQString toString(const int first=64) const;
    QQStringList segment(const int segmentBytes) const;

public:
    QQByteArray takeRight(const int aCount);

private:
    QQByteArray it() const { return *this; }
    QQByteArray &it() { return *this; }

public: // debug
    QQString toInfoString(const int first=64) const;
    QQString toDebugString(const int first=64) const;
};

Q_DECLARE_METATYPE(QQByteArray);
