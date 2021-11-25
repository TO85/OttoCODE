#include "Denominators.h"

#include <cmath>

#include <eirXfr/Debug.h>

const Denominators::TermList Denominators::scmPrimes =
{
#include "../../resources/eirType/Primes1E6.hh"
};


Denominators::TermCountList Denominators::list() const
{
//    TRACEQFI << mTermCountMap;
    TermCountList result;
    if (isNegative()) result << TermCount(-1, mNegativeCount);
    for (Term term : mTermCountMap.keys())
    {
        Count count = mTermCountMap.value(term);
        TermCount pair(term, count);
        result << pair;
    }
//    DUMPVAL(result);
    return result;
}

Denominators::Term Denominators::product() const
{
//    TRACEQFI << mNegativeCount << mTermCountMap;
    Term result = 1;
    for (Term term : mTermCountMap.keys())
    {
        Count count = mTermCountMap.value(term);
        Term termProduct = pow(term, count);
        result *= termProduct;
//        TRACE << term << count << termProduct << result;
    }
    if (isNegative())
        result = - result;
//    DUMPVAL(result);
    return result;
}

void Denominators::append(const Denominators::Term aTerm)
{
//    TRACEQFI << aTerm;
    mInputTermList.append(aTerm);
    Term subject;
    if (aTerm < 0)
        ++mNegativeCount, subject =  - aTerm;
    else
        subject = aTerm;
    AEXPECTEQ(2, scmPrimes.first());
    if (subject < scmPrimes.first())
    {
        mTermCountMap[subject] = 1;
        return;                                                 /* /=======\ */
    }
    Index primeIndex = 0;
    while (primeIndex < primeCount() && subject > 1)
    {
        Term thisPrime = prime(primeIndex);
        Count oldCount = mTermCountMap.value(thisPrime);
        while (0 == subject % thisPrime)
        {
            mTermCountMap[thisPrime]++;
            subject /= thisPrime;
        }
        if (mTermCountMap.value(thisPrime) != oldCount)
            TRACE << thisPrime << oldCount << mTermCountMap.value(thisPrime);
        ++primeIndex;
    }
    if (subject != 1)
    {   // bigger than our prime list, surrender
        WARNQFI << subject << "exceeds prime list";
        mTermCountMap[subject]++;
    }
//    TRACE << mTermCountMap;
    AEXPECTEQ(aTerm, product());
}

void Denominators::remove(const Denominators::TermCountList &other)
{
//    TRACEQFI << other << termPairMap();
    TermPairMap thisTPM = termPairMap();
    TermCountMap removeTPM = termCountMap(other);
    for (Term term : termPairMap().keys())
        if (removeTPM.contains(term))
        {
            Count thisCount = thisTPM.value(term).second;
            Count removeCount = removeTPM.value(term);
//            TRACE << term << thisCount << removeCount;
            if (thisCount == removeCount)
                thisTPM.remove(term);
            else
                thisTPM[term].second = thisCount - removeCount;
//            DUMPVAL(thisTPM);
        }
    set(thisTPM);
//    DUMPVAL(termPairMap());
}

/* ---------------------------- static ------------------------ */

Denominators::TermCountList Denominators::common(Denominators::TermCountList tcl1,
                                                 Denominators::TermCountList tcl2)
{
//    TRACEQFI << "lhs" << tcl1 << "rhs" << tcl2;
    TermCountList result;
    while ( ! tcl1.isEmpty() && ! tcl2.isEmpty())
    {
//        TRACE << "common() while{} lhs" << tcl1 << "rhs" << tcl2;
        if (tcl1.first().first < tcl2.first().first)
        {
            tcl1.removeFirst();
        }
        else if (tcl2.first().first < tcl1.first().first)
        {
            tcl2.removeFirst();
        }
        else
        {
            AEXPECTEQ(tcl1.first().first, tcl2.first().first)
            TermCount tc1 = tcl1.takeFirst(), tc2 = tcl2.takeFirst();
            AEXPECTEQ(tc1.first, tc2.first);
            TermCount tcr(tc1.first, qMin(tc1.second, tc2.second));
            result.append(tcr);
        }
//        DUMPVAL(result);
    }
    return result;
}

/* ---------------------------- private ------------------------ */

void Denominators::set(const Denominators::TermPairMap tpm)
{
//    TRACEQFI << tpm;
    mTermCountMap.clear();
    for (auto tc : tpm) mTermCountMap.insert(tc.first, tc.second);
//    DUMPVAL(mTermCountMap);
}

/* ---------------------------- private static ------------------------ */

Denominators::TermPairMap Denominators::termPairMap(Denominators::TermCountList tcl)
{
//    TRACEQFI << tcl;
    TermPairMap result;
    for (auto tcp : tcl) result.insert(tcp.first, tcp);
//  DUMPVAL(result);
    return result;
}

Denominators::TermPairMap Denominators::termPairMap(Denominators::TermCountMap tcm)
{
//    TRACEQFI << tcm;
    TermPairMap result;
    for (Term term : tcm.keys()) result.insert(term, TermCount(term, tcm.value(term)));
//  DUMPVAL(result);
    return result;
}

Denominators::TermCountMap Denominators::termCountMap(Denominators::TermCountList tcl)
{
//    TRACEQFI << tcl;
    TermCountMap result;
    for (auto tcp : tcl) result.insert(tcp.first, tcp.second);
//  DUMPVAL(result);
    return result;
}

Denominators::TermCountList Denominators::termPairList(Denominators::TermPairMap tpm)
{
//    TRACEQFI << tpm;
    TermCountList result;
    for (Term term : tpm.keys()) result << tpm.value(term);
//  DUMPVAL(result);
    return result;
}

