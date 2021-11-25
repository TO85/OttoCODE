#pragma once

#include <eirType/QQVariant.h>

#include "DomStatus.h"

template <typename VALUE>
class EIRXML_EXPORT DomResult
{
public:
    DomResult() {;}
    DomResult(const DomStatus &aStatus) : mStatus(aStatus) {;}
    DomResult(const DomStatus &aStatus, const VALUE &aVari)
        : mStatus(aStatus), mValue(aVari) {;}

public:
    DomStatus status() const { return mStatus; }
    DomStatus &status() { return mStatus; }
    VALUE value() const { return mValue; }
    VALUE &value() { return mValue; }
    DomStatus append(const DomStatus &more) { return status().append(more); }

private:
    DomStatus mStatus;
    VALUE mValue;
};

/* --------------------- explicit template instantiation  ------------------ */
#include <IfData/InputIndi1BitMask.h>
#include <IfData/OutputIndi1BitMask.h>
#include <IfData/MeanFaceIndi1MaskedFloatVector.h>
#include <IfData/WeightMaskIndi1MaskedFloatVector.h>
#include <IfData/FaceLayersIndi1MaskedFloatVectorSet.h>
template class DomResult<InputIndi1BitMask>;
template class DomResult<OutputIndi1BitMask>;
template class DomResult<MeanFaceIndi1MaskedFloatVector>;
template class DomResult<WeightMaskIndi1MaskedFloatVector>;
template class DomResult<FaceLayersIndi1MaskedFloatVectorSet>;

