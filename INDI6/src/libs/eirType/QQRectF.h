#pragma once
#include "eirType.h"

#include <QtCore/QRectF>

#include <QtCore/QList>
#include <QtCore/QMetaType>

#include "QQRect.h"

class EIRTYPE_EXPORT QQRectF : public QRectF
{
public:
    typedef QList<QQRectF> List;

public:
    QQRectF() = default;
    QQRectF(const QRectF other) : QRectF(other) {;}
    QQRectF(const QQRect iRect) : QRectF(iRect) {;}
    QQRectF(const QQRectF &other) = default;
    QQRectF &operator = (const QQRectF &other) = default;
    ~QQRectF() = default;

    QQRect toRect() const;
    operator QQRect () { return toRect(); }
};

Q_DECLARE_METATYPE(QQRectF);


