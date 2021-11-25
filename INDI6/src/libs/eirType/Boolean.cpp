#include "Boolean.h"

#include <QtDebug>
#include <QtCore/QString>

QString Boolean::toString() const
{
    if (mValid)
        return mBool ? "true" : "false";
    else
        return mBool ? "{invalid}" : "{null}";
}

QDebug operator<<(QDebug dbg, const Boolean &boolean)
{
    dbg << boolean.toString(); return dbg;
}
