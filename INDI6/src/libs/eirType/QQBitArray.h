#pragma once
#include "eirType.h"

#include <QtCore/QBitArray>

#include <QtCore/QMetaType>

#include "Boolean.h"
#include "QQPoint.h"
#include "QQSize.h"

class EIRTYPE_EXPORT QQBitArray : public QBitArray
{
public:
    QQBitArray(const QBitArray &other) : QBitArray(other), mSize(other.count(), 0) {;}
    QQBitArray(const QQBitArray &other, const QQSize aSize) : QBitArray(other), mSize(aSize) {;}
    QQBitArray(const int aCount, const bool aBool=false) : QBitArray(aCount, aBool), mSize(aCount, 0) {;}
    QQBitArray(const QQSize aSize, const bool aBool=false) : QBitArray(aSize.count(), aBool), mSize(aSize) {;}
    QQBitArray() = default;
    QQBitArray(const QQBitArray &other) = default;
    ~QQBitArray() = default;
    QQBitArray &operator = (const QQBitArray &other) = default;

public: // access
    QQSize size() const { return mSize; }
    int width() const { return size().width(); }
    int height() const { return size().height(); }
    bool isValid(const int index) const;
    bool isValid(const QQPoint aPoint) const;
    bool value(const int ix) const;
    bool value(const QQPoint pt) const;
    bool isZero() const;
    QQStringList toStrings(const QQChar trueChar=QQChar('+'),
                           const QQChar falseChar=QQChar('-'),
                           const int subSample=1) const;

public: // setters
    void set(const QQSize sz) { mSize = sz; }
    void set(const int ix, const bool b=true) { setBit(ix, b); }
    void set(const QQPoint pt, const bool b=true) { setBit(mSize.index(pt), b); }
    void reset(const int ix) { set(ix, false); }
    void reset(const QQPoint pt) { set(pt, false); }

private:
    QQBitArray it() const { return *this; }
    QQBitArray &it() { return *this; }

private:
    QQSize mSize;
};

Q_DECLARE_METATYPE(QQBitArray);
