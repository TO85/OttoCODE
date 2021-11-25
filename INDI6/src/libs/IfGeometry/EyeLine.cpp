#include "EyeLine.h"

#include <eirXfr/Debug.h>

EyeLine::EyeLine(const QQPoint center, const int distance, const QQPoint offset)
{
    setLeft(center + QQPoint( - distance / 2, 0)),
            setRight(center + QQPoint( + distance / 2, 0)),
            set(offset);
    TRACEQFI << center << distance << offset << toDebugString();
}

EyeLine::EyeLine(const EyeLineF elf, const QQSize size, const QQPoint offset)
{
    setLeft( QQPoint(qRound(elf.left().x()  * size.width()), qRound(elf.left().y()  * size.height())));
    setRight(QQPoint(qRound(elf.right().x() * size.width()), qRound(elf.right().y() * size.height())));
    TRACEQFI << elf << size << offset << toDebugString();
}

QQString EyeLine::toDebugString() const
{
    if (isNull())
        return "{EyeLine: null}";
    else
        return QQString("{EyeLine: %1 offset=%2 (%3)}").arg(QQLine::toDebugString(),
                        offset().toDebugString(), offsetLine().toDebugString());
}
