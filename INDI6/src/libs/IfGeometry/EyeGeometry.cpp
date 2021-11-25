#include "EyeGeometry.h"

#include <eirXfr/Debug.h>


EyeGeometry::EyeGeometry(const ObjectType &eyeType, const SCRect detectedEye,
                         const ObjectType &faceType, const SCRect faceRect)
{
    set(eyeType, detectedEye, faceType, faceRect);
}

void EyeGeometry::set(const ObjectType &eyeType, const SCRect detectedEye,
                      const ObjectType &faceType, const SCRect faceRect)
{
    EXPECT(eyeType.isEye());
    mEyeType = eyeType;
    mDetectedEye = detectedEye;
    EXPECT(faceType.isFaceFrontal());
    switch (faceType.value())
    {
    case ObjectType::FaceFrontalFull:
        mFaceGeometry.setFullFace(faceRect);
        mFaceType = faceType, mFaceRect = faceRect;
        break;

    case ObjectType::FaceFrontalTight:
        mFaceGeometry.setTightFace(faceRect);
        mFaceType = faceType, mFaceRect = faceRect;
        break;

    case ObjectType::FaceFrontalHead:
        mFaceGeometry.setHeadRect(faceRect);
        mFaceType = faceType, mFaceRect = faceRect;
        break;

    default:
        break;
    }
}
