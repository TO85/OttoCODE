#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QPair>


#include "Rational.h"

class EIRTYPE_EXPORT Denominators
{
public:
    typedef long long signed Term;
    typedef long long unsigned Count;
    typedef Count Index;
    typedef QPair<Term, Count> TermCount;
    typedef QList<Term> TermList;
    typedef QList<TermCount> TermCountList;
    typedef QMap<Term, Count> TermCountMap;
    typedef QMap<Term, TermCount> TermPairMap;

public:
    Denominators() {;}
    Denominators(const Term &t) { set(t); }

    TermList terms() const { return mInputTermList; }
    TermCountMap map() const { return mTermCountMap; }
    Denominators &it() { return *this; }
    Denominators it() const { return *this; }

    bool isNegative() const { return mNegativeCount & 1; }
    TermList termlist() const;
    TermCountList list() const;
    Term product() const;

    void clear() { mInputTermList.clear(), mTermCountMap.clear(); }
    void append(const Term t);
    void set(const Term t) { clear(); append(t); }
    void remove(const TermCountList &other);

public: // static
    static TermCountList common(TermCountList tcl1, TermCountList tcl2);
    static TermCountList common(Denominators d1, Denominators d2)
    { return common(d1.list(), d2.list()); }

private:
    TermPairMap termPairMap() const { return termPairMap(mTermCountMap); }
    void set(const TermPairMap tpm);

private: // static
    static TermPairMap termPairMap(TermCountList tcl);
    static TermCountMap termCountMap(TermCountList tcl);
    static TermPairMap termPairMap(TermCountMap tcm);
    static TermCountList termPairList(TermPairMap tpm);
    static TermList primes() { return scmPrimes; }
    static Count primeCount() { return scmPrimes.count(); }
    static Term prime(const Index ix) { return scmPrimes.value(ix, 1); }

private: // static const
    static const TermList scmPrimes;

private:
    TermList mInputTermList;
    Count mNegativeCount=0;
    TermCountMap mTermCountMap;
};

