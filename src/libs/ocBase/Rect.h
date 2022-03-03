#pragma once

#include <QPoint>
#include <QSize>

class Rect
{
public:
    Rect();
    Rect(const QSize size, const QPoint center);

private:
    QSize mSize;
    QPoint mCenter;
};

