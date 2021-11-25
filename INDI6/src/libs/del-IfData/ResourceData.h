#pragma once
#include "IfData.h"

#include "MainResource.h"

class IFDATA_EXPORT ResourceData
{
public:
    explicit ResourceData() = default;
    ResourceData(const ResourceData &other) = default;
    ~ResourceData() = default;
    ResourceData &operator = (const ResourceData &other) = default;

public:
    MainResource mainData() const { return mMainData; }
#if 0
    InputIndi1BitMask inputMask() const { return mInputMask; }
    OutputIndi1BitMask outputMask() const { return mOutputMask; }
    MeanFaceIndi1MaskedFloatVector meanFace() const { return mMeanFace; }
    WeightMaskIndi1MaskedFloatVector WeightMask() const { return mWeightMask; }
    FaceLayersIndi1MaskedFloatVectorSet LayerSet() const { return mLayerSet; }
#endif

public:
    void clear();
    void set(const MainResource &aMainData) { mMainData = aMainData; }
#if 0
    void set(const InputIndi1BitMask &aInputMask) { mInputMask = aInputMask; }
    void set(const OutputIndi1BitMask &aOutputMask) { mOutputMask = aOutputMask; }
    void set(const MeanFaceIndi1MaskedFloatVector &aMeanFace) { mMeanFace = aMeanFace; }
    void set(const WeightMaskIndi1MaskedFloatVector &aWeightMask) { mWeightMask = aWeightMask; }
    void set(const FaceLayersIndi1MaskedFloatVectorSet &aLayerSet) { mLayerSet = aLayerSet; }
#endif

private:
    MainResource mMainData;
#if 0
    InputIndi1BitMask mInputMask;
    OutputIndi1BitMask mOutputMask;
    MeanFaceIndi1MaskedFloatVector mMeanFace;
    WeightMaskIndi1MaskedFloatVector mWeightMask;
    FaceLayersIndi1MaskedFloatVectorSet mLayerSet;
#endif
};

Q_DECLARE_METATYPE(ResourceData);

