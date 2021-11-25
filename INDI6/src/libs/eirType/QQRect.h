#pragma once
#include "eirType.h"

#include <QtDebug>
#include <QtCore/QMetaType>
#include <QtCore/QRect>

#include "QQLine.h"
#include "QQPoint.h"
#include "QQSize.h"

class EIRTYPE_EXPORT QQRect : public QRect
{
public:
    QQRect() = default;
    QQRect(const QRect other) : QRect(other) {;}
    QQRect(const QQPoint topLeft, const QQSize size) : QRect(topLeft, size) {;}
    QQRect(const QQRect &other) = default;
    ~QQRect() = default;
    QQRect &operator = (const QQRect &other) = default;

    QQPoint topCenter() const { return QQPoint(center().x(), top()); }
    QQPoint bottomCenter() const { return QQPoint(center().x(), bottom()); }
    QQPoint middleLeft() const { return QQPoint(left(), center().y()); }
    QQPoint middleRight() const { return QQPoint(right(), center().y()); }
    QQLine centerLine() const { return QQLine(topCenter(), bottomCenter()); }
    QQLine middleLine() const { return QQLine(middleLeft(), middleRight()); }
    QQRect intersected(const QQRect &other) const { return QRect::intersected(other); }
    QQSize size() const { return QRect::size(); }
    int area() const { return size().area(); }

    QQString toDebugString() const;
};

Q_DECLARE_METATYPE(QQRect);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQRect qqrc);
