#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMetaType>

#include "SCRect.h"
#include "QQPointF.h"
#include "QQRectF.h"
#include "QQSizeF.h"

class EIRTYPE_EXPORT SCRectF
{
public:
    SCRectF() = default;
    SCRectF(const QQSizeF size, const QQPointF center) : mSize(size), mCenter(center) {;}
    SCRectF(const QQSizeF size) : mSize(size), mCenter(size.center()) {;}
    SCRectF(const QQRectF qrc) : mSize(qrc.size()), mCenter(qrc.center()) {;}
    SCRectF(const SCRectF &other) = default;
    ~SCRectF() = default;
    SCRectF &operator = (const SCRectF &other) = default;

    QQPointF center() const { return mCenter; }
    QQSizeF size() const { return mSize; }
    bool isNull() const { return size().isNull(); }
    qreal width() const { return size().width(); }
    qreal height() const { return size().height(); }
    qreal top() const { return center().y() - (height() / 2); }
    qreal bottom() const { return center().y() + (height() / 2) - 1; }
    qreal left() const { return center().x() - (width() / 2); }
    qreal right() const { return center().x() + (width() / 2) - 1; }
    QQPointF topLeft() const { return QQPointF(left(), top()); }
    QQPointF bottomRight() const { return QQPointF(right(), bottom()); }
    bool equals(const SCRectF &other) const
    { return mSize.fuzzyCompare(other.size()) && mCenter.fuzzyCompare(mCenter); }
    bool operator == (const SCRectF &other) { return equals(other); }
    SCRect toRect() const;
    SCRect toRect(const QQSize size) const;
    SCRect toRect(const SCRect scrc) const;
    SCRect toRect(const unsigned width) const;

private:
    QQSizeF mSize;
    QQPointF mCenter;
};

Q_DECLARE_METATYPE(SCRectF);

