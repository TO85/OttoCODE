#pragma once
/*! \file ResourceSet.h */
#include "IfData.h"

#include <QtCore/QString>

#include <eirType/BasicName.h>
#include <eirType/QQLine.h>
#include <eirType/QQSize.h>
#include <eirType/QQVector.h>
#include <eirXml/QQDomElement.h>

#include "ResourceBaseData.h"
#include "ResourceBitMask.h"
#include "ResourceFloatVector.h"
#include "ResourceType.h"

class IFDATA_EXPORT ResourceValues
{
public:
    ResourceValues();

public: // getters
    QQStringList info() const;
    ResourceBaseData baseData() const { return mResourceBaseData; }
    ResourceBitMask inputBitMask() const { return mInputBitMask; }
    ResourceBitMask outputBitMask() const { return mOutputBitMask; }
#if 0
    ResourceFloatVector meanFaceVector() const;
    ResourceFloatVector weightMaskVector() const;
    ResourceFloatVector faceLayerVector(const int index) const;
#endif

private:
    friend class ResourceManager;
    void setResourceBaseData(const ResourceBaseData &aBaseData);
    void setResourceBitMask(const ResourceType aType, const ResourceBitMask &aBitMask);

private:
    ResourceBaseData mResourceBaseData;
    ResourceBitMask mInputBitMask;
    ResourceBitMask mOutputBitMask;
#if 0
    ResourceFloatVector mMeanFaceVector;
    ResourceFloatVector mWeightMaskVector;
    QQVector<ResourceFloatVector> mFaceLayerVectors;
#endif
};

