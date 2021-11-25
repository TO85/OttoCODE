#pragma once
#include "eirType.h"

#include <QtCore/QLineF>
#include <QtCore/QMetaType>

class EIRTYPE_EXPORT QQLineF : public QLineF
{
public:
    QQLineF() = default;
    QQLineF(const QPointF pt1, const QPointF pt2) : QLineF(pt1, pt2) {;}
    QQLineF(const QQLineF &other) = default;
    ~QQLineF() = default;
    QQLineF &operator = (const QQLineF &other) = default;

    qreal rise() const { return p2().y() - p1().y(); }
    qreal run()  const { return p2().x() - p1().x(); }
    qreal slope() const { return qIsNull(run()) ? qQNaN() : rise() / run(); }
    QQLineF swapped() const { return QQLineF(p2(), p1()); }

    void swap() { QPointF t = p1(); setP1(p2()); setP2(t); }
};

Q_DECLARE_METATYPE(QQLineF);


