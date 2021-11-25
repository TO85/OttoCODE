#include "cvQRect.h"

QString cvQRect::toString() const
{
    return QString("cvQRect sz=%1Wx%2H tl=%3L,%4T c=%5X,%6Y").arg(size().width).arg(size().height)
            .arg(topLeft().x()).arg(topLeft().y()).arg(center().x()).arg(center().y());

}
