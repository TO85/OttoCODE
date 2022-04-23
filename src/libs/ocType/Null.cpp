#include "Null.h"


bool Null::isNull() const
{
    if (isInvalid()) return true;
    else if (isValid() && notTrue()) return true;
    else return false;
}
