#pragma once
#include "eirType.h"

#include <QtCore/QSizeF>

#include <QtCore/QList>
#include <QtCore/QMetaType>

#include "QQPointF.h"
#include "QQSize.h"

class EIRTYPE_EXPORT QQSizeF : public QSizeF
{
public:
    typedef QList<QQSizeF> List;

public:
    QQSizeF() = default;
    QQSizeF(const qreal aWidth, const qreal aHeight) : QSizeF(aWidth, aHeight) {;}
    QQSizeF(const QSizeF other) : QSizeF(other) {;}
    QQSizeF(const QQSizeF &other) = default;
    ~QQSizeF() = default;
    QQSizeF &operator = (const QQSizeF &other) = default;

    QQPointF center() const { return QQPointF(width() / 2.0, height() / 2.0); }
    qreal area() const { return width() * height(); }
    bool fuzzyCompare(const QQSizeF &other) const;
    QQSize toSize() const { return QQSize(qRound(width()), qRound(height())); }
    bool operator == (const QQSizeF &other) const { return fuzzyCompare(other); }
    operator QQSize () const{ return toSize(); }

};

Q_DECLARE_METATYPE(QQSizeF);


