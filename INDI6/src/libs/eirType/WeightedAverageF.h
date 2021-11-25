#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QMetaType>

#include "BasicName.h"
#include "DualMap.h"
#include "QQStringList.h"

class EIRTYPE_EXPORT WeightedAverageF
{
public:
    typedef int Key;
    typedef BasicName Name;
    typedef qreal Value;
    typedef qreal Weight;

public:
    WeightedAverageF() = default;
    WeightedAverageF(const WeightedAverageF &other) = default;
    ~WeightedAverageF() = default;
    WeightedAverageF &operator = (const WeightedAverageF &other) = default;

public:
    int count() const;
    bool isEmpty() const { return 0 == count(); }
    int size() const { return count(); }
    qreal calculate() const;

public:
    void clear();
    void zeroValues();
    bool appendWeight(const Key aKey, const Name &aName, const Weight aWeight);
    bool setValue(const Key aKey, const Value aScore);
    //bool setValue(const Name &aName, const Value aValue);

public:
    QQStringList toDebugStrings() const;

private:
    DualMap<int, BasicName> mKeyNameDMap;
    QMap<int, qreal> mIndexWeightMap;
    QMap<int, qreal> mIndexValueMap;
};

Q_DECLARE_METATYPE(WeightedAverageF);

