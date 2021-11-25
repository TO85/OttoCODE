#pragma once
#include "IfData.h"

#include <eirType/QQString.h>

#include "LayerIndi1MaskedFloatVector.h"

class FaceLayersIndi1MaskedFloatVectorSet
{
public:
    FaceLayersIndi1MaskedFloatVectorSet(const int aMaxLayers=320)
        : mMaxLayers(aMaxLayers), mLayerVector(mMaxLayers) {;}

public:
    void clear() { mMaxLayers = 0, mLayerVector.clear(); }
    void set(const LayerIndi1MaskedFloatVector &aLayer);

protected:

private:
    QQString doctypeExpected() const;
    bool isValidIndex(const int ix) { return ix >= 0 && ix < mMaxLayers; }

private:
    int mMaxLayers;
    QVector<LayerIndi1MaskedFloatVector> mLayerVector;
};

