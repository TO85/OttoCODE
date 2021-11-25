#pragma once
#include "IfData.h"

class VectorLayerData
{
public:
    typedef QVector<VectorLayerData> Vector;

public:
    explicit VectorLayerData() = default;
    VectorLayerData(const int aLayerIndex) : mLayerIndex(aLayerIndex) {;}
    VectorLayerData(const VectorLayerData &other) = default;
    ~VectorLayerData() = default;
    VectorLayerData &operator = (const VectorLayerData &other) = default;

public:
    const FloatVector vectorData() const { return mData; }

private:
    int mLayerIndex=-1;
    int mActivePixels=0;
    FloatPixel mMinValue=qQNaN();
    FloatPixel mMaxValue=qQNaN();
    FloatVector mData;

};

Q_DECLARE_METATYPE(VectorLayerData);
