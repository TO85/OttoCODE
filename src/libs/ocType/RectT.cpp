#include "Rect.h"

Rect::Rect() : mSize(-1, -1), mCenter(0, 0) {;}
Rect::Rect(const QSize size, const QPoint center) : mSize(size), mCenter(center) {;}

