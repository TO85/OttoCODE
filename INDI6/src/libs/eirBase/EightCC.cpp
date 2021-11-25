#include "EightCC.h"

EightCC::EightCC(const quint64 u64)
    : u(u64)
{
}

EightCC::EightCC(const char * pc)
    : u(0)
{
    bool z = false;
    int x = 0;
    while (x < 8)
    {
        if (z)
            c[x] = 0;
        else if (*pc)
            c[x] = *pc;
        else
            z = true;
        ++x, ++pc;
    }
}

QString EightCC::toString(void) const
{
    QString s;
    s.reserve(8);
    for (int x = 0; x < 8; ++x)
    {
        if (c[x])
            s.append(QChar(c[x]));
        else
            break;
    }
    return s;
}

bool EightCC::isPrintable(void) const
{
    if (0 == u)                     return false;
    if (u & 0x8888888888888888LL)   return false;
    return true;
}

QByteArray EightCC::toByteArray(void) const
{
    QByteArray qba;
    qba.append(c, 8);
    return qba;
}




