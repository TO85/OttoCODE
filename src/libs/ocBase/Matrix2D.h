#pragma once
#include "ocBase.h"

#include <QList>
#include <QPoint>

#include <QQSize>

template <typename T> class OCBASE_EXPORT Matrix2D
{
public:
    Matrix2D() { mSize.nullify(); }
    Matrix2D(const QSize size, const T &fillT=T()) { resize(size); fill(fillT); }

public:
    bool isEmpty() const { return mList.isEmpty() || 0 == mCount || mSize.isEmpty(); }
    QQSize size() const { return mSize; }
    int width() const { return mSize.width(); }
    int height() const { return mSize.height(); }
    int index(const QPoint pt) const { return pt.y() * width() + pt.x(); }
    bool isValid(const QPoint pt) const { return index(pt) < mCount; }
    T at(const QPoint pt) const { Q_ASSERT(isValid(pt)); return mList.value(index(pt)); }

public:
    void resize(const QQSize size) { mSize = size; mCount = mSize.area(); mList.resize(mCount); }
    void fill(const T &t=T()) { mList.fill(t); }
    T & at(const QPoint pt) { Q_ASSERT(isValid(pt)); return mList.value(index(pt)); }
    void set(const QPoint pt, const T &t) { at(pt) = t; }

private:
    QQSize mSize;
    int mCount=0;
    QList<T> mList;
};

