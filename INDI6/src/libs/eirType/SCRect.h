#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMetaType>
#include <QtCore/QMultiMap>
#include <QtCore/QPair>
#include <QtCore/QVector>

#include "QQLine.h"
#include "QQLineF.h"
#include "QQList.h"
#include "QQPoint.h"
#include "QQPointF.h"
#include "QQRect.h"
#include "QQRectF.h"
#include "QQSize.h"
#include "QQVector.h"
#include "QQSizeF.h"
#include "Rational.h"

class EIRTYPE_EXPORT SCRect
{
public:
    typedef QPair<SCRect, SCRect> Pair;
    typedef QQList<SCRect> List;
    typedef QQVector<SCRect> Vector;

public:
    SCRect() = default;
    SCRect(const SCRect &other) = default;
    SCRect(const QQSize aSize, const QQPoint aCenter) : mSize(aSize), mCenter(aCenter) {;}
    SCRect(const QQSize aSize) : mSize(aSize), mCenter(aSize.center()) {;}
    SCRect(const QQPoint aTopLeft, const QQSize aSize) : mSize(aSize),
        mCenter(aTopLeft.x() + (mSize.width() / 2), aTopLeft.y() + (mSize.height() / 2)) {;}
    SCRect(const QQRect qqrc) : mSize(qqrc.size()), mCenter(qqrc.center()) {;}
    ~SCRect() = default;
    SCRect &operator=(const SCRect &other) = default;

public:
    QQSize size() const { return mSize; }
    QQPoint center() const { return mCenter; }
    QQPoint &center() { return mCenter; }

public:
    bool isNull() const { return size().isEmpty() || center().notValid() || center().isOrigin(); }
    QQSizeF sizeF() const { return QQSizeF(mSize); }
    int width() const { return size().width(); }
    int height() const { return size().height(); }
    int top() const { return center().y() - (height() / 2); }
    int bottom() const { return center().y() + (height() / 2) - 1; }
    int left() const { return center().x() - (width() / 2); }
    int right() const { return center().x() + (width() / 2) - 1; }
    QQPoint topLeft() const { return QQPoint(left(), top()); }
    QQPoint topRight() const { return QQPoint(right(), top()); }
    QQPoint bottomLeft() const { return QQPoint(left(), bottom()); }
    QQPoint bottomRight() const { return QQPoint(right(), bottom()); }
    bool isSquare() const { return size().isSquare(); }
    bool contains(const SCRect &other) const { return toRect().contains(other); }
    bool contains(const QQPoint &pt) const;
    bool intersects(const SCRect &other) const;
    QQPointF relative(const QPoint pt) const;
    QQLineF relative(const QQLine ln) const;
    QQLine lineFrom(const QQPoint pt=QQPoint(0,0)) const { return QQLine(pt, center()); }
    int area() const { return mSize.area(); }
    Rational overlapRatio(const SCRect &other) const;
    bool equals(const SCRect &other) const;
    SCRect scaled(const qreal f) const { return SCRect((sizeF() * f).toSize(), center()); }
    SCRect scaled(const qreal f, const int clip) const;
    SCRect resized(const qreal f) const { return SCRect((sizeF() * f).toSize(), center()); }
    SCRect translated(const QQPoint dxy) const { return SCRect(size(), center() + dxy); }
    QRect toQRect() const { return QRect(topLeft(), size()); }
    QQRect toRect() const { return QQRect(topLeft(), size()); }
    QQRectF toRectF() const { return QQRectF(toRect()); }
    SCRect squaredByArea() const;
    SCRect operator * (const qreal f) { return scaled(f); }
    bool operator == (const SCRect &other) { return equals(other); }
    operator QRect () const { return toRect(); }
    operator QString() const { return toDebugString(); }
    QVariant toVariant() const;

public:
    void set(const SCRect &other) { it() = other; }
    void setCenter(const QQPoint center) { mCenter = center; }
    void setSize(const QQSize sz) { mSize = sz; }
    void setSize(const int aWidth, const int aHeight) { setSize(QQSize(aWidth, aHeight)); }
    void setQQRect(const QQRect qqrc) { mSize = qqrc.size(), mCenter = qqrc.center(); }
    void nullify() { mSize.nullify(), mCenter.nullify(); }
    void squareByArea() { it() = squaredByArea(); }
    void unite(const SCRect other);
    void translate(const QQPoint dxy) { it() = translated(dxy); }
    SCRect madeSquare();
    void operator += (const SCRect other) { unite(other); }

public: // static

private:
    SCRect &it() { return *this; }
    SCRect it() const { return *this; }

public: // debug
    QString toDebugString() const;

private:
    QQSize mSize;
    QQPoint mCenter;
};

Q_DECLARE_METATYPE(SCRect);

extern EIRTYPE_EXPORT QDebug operator<<(QDebug dbg, const SCRect &scrc);
extern EIRTYPE_EXPORT bool operator == (const SCRect &scrc, const SCRect &other);
extern EIRTYPE_EXPORT void swap(const SCRect &scrc, const SCRect &other);

