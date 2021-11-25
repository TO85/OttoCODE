#include "eirType.h"

#include <cfloat>
#include <cmath>

#include <eirXfr/Debug.h>

eirType::eirType()
{
}


unsigned powerOfTwoDown(const unsigned u)
{
    unsigned result=0;
    double log2res;
    double log2u = log2(double(u));
    log2res = double(unsigned(log2u));
    result = exp2(log2res);
    TRACEQFI << u << "-->" << result;
    return result;

}
unsigned powerOfTwo(const unsigned u)
{
    unsigned result=0;
    double log2res;
    double log2u = log2(double(u));
    log2res = double(qRound(log2u));
    result = exp2(log2res);
    TRACEQFI << u << "-->" << result;
    return result;
}

unsigned powerOfTwoUp(const unsigned u)
{
    unsigned result=0;
    double log2res;
    double log2u = log2(double(u));
    log2res = double(unsigned(log2u + 1.0L - DBL_MIN));
    result = exp2(log2res);
    TRACEQFI << u << "-->" << result;
    return result;

}

