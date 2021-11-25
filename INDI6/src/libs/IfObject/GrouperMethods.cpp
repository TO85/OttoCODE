#include "GrouperMethods.h"

#include <eirXfr/Debug.h>

bool GrouperMethods::isCombine() const
{
    const int begin = $beginCombine;
    const int end = $endCombine;
    const bool result = value() > begin && value() < end;
//  TRACEQFI << name() << value() << begin << end << result;
    return result;
}

bool GrouperMethods::isGroup() const
{
    const int begin = $beginGroup;
    const int end = $endGroup;
    const bool result = value() > begin && value() < end;
//  TRACEQFI << name() << value() << begin << end << result;
    return result;
}


DEFINE_ENUMERATION(GrouperMethods, GROUPERMETHODS_ENUM);
