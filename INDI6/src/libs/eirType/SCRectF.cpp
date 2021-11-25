#include "SCRectF.h"


SCRect SCRectF::toRect() const
{
    return SCRect(QQSize(qRound(width()), qRound(height())),
                  QQPoint(qRound(center().x()), qRound(center().y())));
}

SCRect SCRectF::toRect(const QQSize size) const
{
    return SCRect(QQSize(qRound(width() * size.width()),
                         qRound(height() * size.height())),
                  QQPoint(qRound(center().x()) * size.width(),
                          qRound(center().y()) * size.height()));
}

SCRect SCRectF::toRect(const SCRect scrc) const
{
    qreal w  = qreal(scrc.width())  * width();
    qreal h  = qreal(scrc.height()) * height();
    qreal dx = qreal(scrc.width())  * center().x();
    qreal dy = qreal(scrc.height()) * center().y();
    int cx = scrc.center().x() + qRound(dx);
    int cy = scrc.center().y() + qRound(dy);
    return SCRect(QQSize(qRound(w), qRound(h)), QQPoint(cx, cy));
}

SCRect SCRectF::toRect(const unsigned scale) const
{
    return SCRect(QQSize(qRound(width() * scale),
                         qRound(height() * scale)),
                  QQPoint(qRound(center().x()) * scale,
                          qRound(center().y()) * scale));
}
