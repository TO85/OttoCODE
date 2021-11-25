#include "QQSizeF.h"

bool QQSizeF::fuzzyCompare(const QQSizeF &other) const
{
    return qFuzzyCompare(width(), other.width())
            && qFuzzyCompare(height(), other.height());
}

