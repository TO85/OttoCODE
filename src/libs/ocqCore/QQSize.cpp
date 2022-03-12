#include "QQSize.h"


int QQSize::area() const
{
    return width() * height();
}

void QQSize::nullify()
{
    it() = null();
}

QQSize QQSize::smNull = QQSize(0, 0);

QQSize QQSize::null()
{
    return smNull;
}
