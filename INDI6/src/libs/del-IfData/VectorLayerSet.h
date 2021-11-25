#pragma once
#include "IfData.h"

#include "VectorLayerData.h"

class VectorLayerSet
{
public:
    explicit VectorLayerSet() = default;
    VectorLayerSet(const int aMaxLayers);
    VectorLayerSet(const VectorLayerSet &other) = default;
    ~VectorLayerSet() = default;
    VectorLayerSet &operator = (const VectorLayerSet &other) = default;

    const VectorLayerData &vectorData(const int layer);

private:
    int mMaxLayers=0;
    VectorLayerData::Vector mLayerSet;
};

Q_DECLARE_METATYPE(VectorLayerSet);
