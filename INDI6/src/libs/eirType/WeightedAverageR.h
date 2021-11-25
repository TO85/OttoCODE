#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QPair>

#include "Rational.h"

class EIRTYPE_EXPORT WeightedAverage
{
public:
    typedef int Key;
    typedef Rational Weight;
    typedef Rational Value;
    typedef QPair<Key, Weight> WeightPair;
    typedef QPair<Key, Value> ValuePair;
    typedef QList<Key> KeyList;
    typedef QList<WeightPair> WeightPairList;
    typedef QList<ValuePair> ValuePairList;
    typedef QMap<Key, Weight> WeightMap;
    typedef QMap<Key, Value> ValueMap;

public:
    WeightedAverage();
    WeightedAverage(const WeightPairList &wpl) { setWeights(wpl); }

    Value result() const { return mResult; }
    Weight weight(const Key key) const { return mWeightMap.value(key); }
    Weight value(const Key key) const { return mValueMap.value(key); }
    Weight product(const Key key) const { return mWeightMap.value(key) * mValueMap.value(key); }
    KeyList uniqueKeys() const { return unique(mWeightMap.keys() + mValueMap.keys()); }

    bool isValidWeights() const;
    bool isValidValues() const;
    bool isValidResult() const { return mResult.isValid(); }
    bool isValid() const { return isValidWeights() && isValidValues(); }
    bool notValid() const { return ! isValid(); }

    void reset() { resetValues(), resetWeights(); }
    void resetValues() { mValueMap.clear(); }
    void resetWeights() { mWeightMap.clear(); }
    void setWeights(const WeightPairList &aWeightPairList);
    void setWeight(const WeightPair &aWeightPair)
    { mWeightMap.insert(aWeightPair.first, aWeightPair.second); }
    void setWeight(const Key aKey, const Weight &aWeight)
    { setWeight(WeightPair(aKey, aWeight)); }
    void setValues(const ValuePairList &aValuePairList);
    void setValue(const Key aKey, const Value aValue)
    { setValue(ValuePair(aKey, aValue)); }
    void setValue(const ValuePair &aValuePair)
    { mValueMap.insert(aValuePair.first, aValuePair.second); }
    Value calculate();
    Value calculate(const ValuePairList &aValuePairList)
    { resetValues(); setValues(aValuePairList); return calculate(); }

    QStringList toDebugStrings() const;
    void dump() const;

private: // static
    static KeyList unique(const KeyList &kl);

private:
    WeightMap mWeightMap;
    ValueMap mValueMap;
    Value mResult;
};

