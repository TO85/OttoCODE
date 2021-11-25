#include "WeightedAverageF.h"

#include <eirXfr/Debug.h>

#include "Success.h"

void WeightedAverageF::clear()
{
    TRACEFN;
    mKeyNameDMap.clear();
    mIndexWeightMap.clear();
    mIndexValueMap.clear();
}

void WeightedAverageF::zeroValues()
{
    TRACEFN;
    for (int aIndex : mIndexValueMap.keys())
        mIndexValueMap[aIndex] = 0.0;
}

bool WeightedAverageF::appendWeight(const int aKey, const BasicName &aName, const qreal aWeight)
{
    TRACEQFI << aKey << aName << aWeight;
    Success success;
    success.expectNot(mKeyNameDMap.contains(aName));
    success.expectNot(mKeyNameDMap.contains(aKey));
    success.expectNot(mIndexWeightMap.contains(aKey));
    success.expectNot(mIndexValueMap.contains(aKey));
    success.validate();
    if (success)
    {
        mKeyNameDMap.insert(aKey, aName);
        mIndexWeightMap.insert(aKey, aWeight);
        mIndexValueMap.insert(aKey, 0.0);
    }
    TRACE << success.toString();
    return success;
}

bool WeightedAverageF::setValue(const Key aKey, const Value aValue)
{
    Success success;
    EXPECT(mKeyNameDMap.contains(aKey));
    success.expect(mKeyNameDMap.contains(aKey));
    success.expect(mIndexWeightMap.contains(aKey));
    success.expect(mIndexValueMap.contains(aKey));
    if (success)
        mIndexValueMap[aKey] = aValue;
    success.validate();
    TRACEQFI << aKey << mKeyNameDMap.at(aKey) << aValue << success.toString();
    return success;
}
/*
bool WeightedAverageF::setValue(const Name &aName, const Value aValue)
{
    const int tKey = mKeyNameDMap.at(aName);
    return setValue(tKey, aValue);
}
*/
int WeightedAverageF::count() const
{
    EXPECTEQ(mKeyNameDMap.count(), mIndexValueMap.size());
    EXPECTEQ(mKeyNameDMap.count(), mIndexValueMap.size());
    return mKeyNameDMap.count();
}

qreal WeightedAverageF::calculate() const
{
    TRACEQFI << mKeyNameDMap.values();
    EXPECTNOT(isEmpty());
    qreal totalValue = 0.0, totalWeight = 0.0, result = 0.0;
    for (int aIndex : mKeyNameDMap.keys())
    {
        Success success;
        success.expect(mKeyNameDMap.contains(aIndex));
        success.expect(mIndexWeightMap.contains(aIndex));
        success.expect(mIndexValueMap.contains(aIndex));
        success.validate();
        if (success)
        {
            const Name aName = mKeyNameDMap.at(aIndex);
            const Weight aWeight = mIndexWeightMap[aIndex];
            const Value aValue = mIndexValueMap[aIndex];
            totalValue += aValue * aWeight, totalWeight += aWeight;
            TRACE << aIndex << aName << aValue << aWeight;
        }
    }
    if ( ! qIsNull(totalWeight))
        result = totalValue / totalWeight;
    TRACE << totalValue << totalWeight << result;
    return result;
}

QQStringList WeightedAverageF::toDebugStrings() const
{
    QQStringList result;
    for (int ix = 0; ix < count(); ++ix)
    {
        result << QQString("#%1 %2 / %3 = %4 >%5<").arg(1 + ix, 3)
                .arg(mIndexValueMap[ix], 8, 'f', 3)
                .arg(mIndexWeightMap[ix], 8, 'f', 3)
                .arg(mIndexValueMap[ix] / mIndexWeightMap[ix], 8, 'f', 3)
                .arg(mKeyNameDMap.at(ix));
    }
    return result;
}

