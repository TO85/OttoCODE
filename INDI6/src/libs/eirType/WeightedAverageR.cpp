#include "WeightedAverageR.h"

#include <eirXfr/Debug.h>

bool WeightedAverage::isValidWeights() const
{
    for (auto k : uniqueKeys())
        if (mWeightMap.value(k).notValid())
        {
            WARN << k << mWeightMap.value(k);
            return false;
        }
    return true;
}

bool WeightedAverage::isValidValues() const
{
    for (auto k : uniqueKeys()) if (mValueMap.value(k).notValid()) return false;
    return true;
}

void WeightedAverage::setWeights(const WeightedAverage::WeightPairList &aWeightPairList)
{
    for (auto wp : aWeightPairList) setWeight(wp);
}

void WeightedAverage::setValues(const WeightedAverage::ValuePairList &aValuePairList)
{
    for (auto vp : aValuePairList) setValue(vp);
}

WeightedAverage::Value WeightedAverage::calculate()
{
    TRACEFN;
    dump();
    Value result(Value::invalid());
    if (notValid()) return result;                                      /* /=======\ */
    Rational totalWeight(0, 1), totalWeightedValue(0, 1);
    for (auto vpk : qAsConst(mValueMap).keys())
    {
        Value v = mValueMap.value(vpk);
        EXPECT(v.isValid());
        v.normalizeSign();
        EXPECT(v.numerator() > 0);
        EXPECT(mWeightMap.contains(vpk));
        if (mWeightMap.contains(vpk) && v.isValid() && v.numerator() > 0)
        {
            Weight w = mWeightMap.value(vpk);
            EXPECT(w.isValid());
            if (w.isValid() && w.notZero())
            {
                v.reduce(), w.reduce();
                totalWeight += w, totalWeightedValue += v * w;
                TRACE << vpk << v << w  << v * w << totalWeightedValue << totalWeight;
            }
        }
    }
    dump();
    DUMPVAL(totalWeightedValue);
    DUMPVAL(totalWeight);
    result.set(totalWeightedValue, totalWeight);
    mResult.set(result);
    DUMPVAL(result);
    AEXPECT(isValidResult());
    return result;
}

void WeightedAverage::dump() const
{
    for (auto vpk : qAsConst(mWeightMap).keys())
        DUMP << vpk << mWeightMap.value(vpk) << mValueMap.value(vpk);
}


/* ------------------------- private static ----------------------- */

WeightedAverage::KeyList WeightedAverage::unique(const WeightedAverage::KeyList &kl)
{
    QMap<Key, int> keyNadaMap;
    for (Key k : kl) keyNadaMap.insert(k, 0);
    return keyNadaMap.keys();
}
