#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>
#include <QtCore/QPointF>

#include "QQPoint.h"

class EIRTYPE_EXPORT QQPointF : public QPointF
{
public:
    QQPointF() = default;
    QQPointF(const QPointF other) : QPointF(other) {;}
    QQPointF(const QQPointF &other) = default;
    QQPointF(const qreal x, const qreal y) : QPointF(x, y) {;}
    QQPointF &operator = (const QQPointF &other) = default;
    ~QQPointF() = default;

    bool notValid() const { return qQNaN() == x() || qQNaN() == y(); }
    bool isValid() const { return ! notValid();}
    bool fuzzyCompare(const QQPointF &other) const;
    QQPoint scaledI(const int factor) const
    { return QQPoint(qRound(x() * qreal(factor)), qRound(y() * qreal(factor))); }
    bool isOrigin() const { return fuzzyCompare(QQPointF()); }
    int distanceI(const QQPoint other=QQPoint()) const;
    qreal distance(const QQPointF other=QQPointF()) const;
    QQPoint negated() const { return QQPoint( - x(), - y()); }
    bool operator == (const QQPointF &other) const { return fuzzyCompare(other); }
    QQPoint operator * (const int factor) { return scaledI(factor); }

    void set(const qreal x, const qreal y) { setX(x), setY(y); }
    void nullify() { set(0.0, 0.0); }
    void invalidate() { set(qQNaN(), qQNaN()); }

    QString toDebugString() const;
};

Q_DECLARE_METATYPE(QQPointF);


