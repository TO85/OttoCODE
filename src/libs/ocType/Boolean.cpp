#include "Boolean.h"

#include <QtDebug>
#include <QtCore/QString>

QString Boolean::toString() const
{
    if (mValid)
        return mTrue ? "true" : "false";
    else
        return "{unknown}";
}

void Boolean::validate(const bool b)
{
    if ( isInvalid() ) mTrue = b;
    mValid = true;
}

QDebug operator<<(QDebug dbg, const Boolean &boolean)
{
    dbg << boolean.toString(); return dbg;
}
