#include "QQBitArray.h"

#include <eirXfr/Debug.h>

#include "QQString.h"
#include "QQStringList.h"

bool QQBitArray::isValid(const int index) const
{
    return index >= 0 && index < count();
}

bool QQBitArray::isValid(const QQPoint aPoint) const
{
    const int tIndex = mSize.index(aPoint);
    return isValid(tIndex);
}

bool QQBitArray::value(const int ix) const
{
    AEXPECT(isValid(ix));
    return testBit(ix);
}

bool QQBitArray::value(const QQPoint pt) const
{
    AEXPECT(isValid(pt));
    const int ix = mSize.index(pt);
    return value(ix);
}

bool QQBitArray::isZero() const
{
    quint64 * p64 = (quint64 *)(bits());
    const int n64 = count() / 64, m64 = count() % 64;
    const int b1 = n64 * 64, e1 = b1 + m64;
    for (int ix64 = 0; ix64 < n64; ++ix64)
        if (0 != p64[ix64]) return false;                               /* /====\ */
    for (int ix1 = b1; ix1 < e1; ++ix1)
        if (true == value(ix1)) return false;                           /* /====\ */
    return true;
}

QQStringList QQBitArray::toStrings(const QQChar trueChar,
                                   const QQChar falseChar,
                                   const int subSample) const
{
    AEXPECT(subSample >= 1);
    QQStringList result;
    if (size().isValid())
    {
        QQString row;
        for (int r = subSample / 2; r < height(); r += subSample)
            for (int c = subSample / 2; c < width(); r += subSample)
            {
                const QQPoint pt(c, r);
                if (isValid(pt))
                    row << (value(pt) ? trueChar : falseChar);
            }
        result << row;
    }
    return result;
}
