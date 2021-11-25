#include "Null.h"

#include <eirXfr/Debug.h>


QDebug operator<<(QDebug dbg, const Null &n)
{
    dbg << n.toString(); return dbg;
}
