#include "VectorLayerSet.h"

VectorLayerSet::VectorLayerSet(const int aMaxLayers)
    : mMaxLayers(aMaxLayers)
{
    mLayerSet.resize(mMaxLayers);
}

const VectorLayerData &VectorLayerSet::vectorData(const int layer)
{
     return mLayerSet[layer];
}
