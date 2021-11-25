#pragma once
#include "IfGeometry.h"

#include <eirType/SCRect.h>

#include "FaceGeometry.h"

class IFGEOMETRY_EXPORT EyeGeometry
{
public:
    EyeGeometry();
    EyeGeometry(const ObjectType &eyeType, const SCRect detectedEye,
                const ObjectType &faceType, const SCRect faceRect);
    void set(const ObjectType &eyeType, const SCRect detectedEye,
             const ObjectType &faceType, const SCRect faceRect);

private:


private:
    ObjectType mEyeType;
    ObjectType mFaceType;
    SCRect mDetectedEye;
    SCRect mFaceRect;
    FaceGeometry mFaceGeometry;

};

