#pragma once
#include "IfGeometry.h"

#include <QtCore/QMetaType>
#include <QtCore/QPair>

#include <eirType/DetectRect.h>
#include <eirType/ObjectType.h>
#include <eirType/QQPoint.h>
#include <eirType/QQPointF.h>
#include <eirType/QQSize.h>
#include <eirType/QQStringList.h>
#include <eirType/SCRect.h>
#include <eirType/SCRectF.h>

#include "EyeLine.h"
#include "EyeROI.h"
#include "FaceTypeRect.h"

class IFGEOMETRY_EXPORT FaceGeometry
{
public:
    FaceGeometry() = default;
    FaceGeometry(const FaceGeometry &other) = default;
    FaceGeometry(const EyeLine eline) { set(eline); }
    FaceGeometry(const FaceTypeRect &faceRect) { set(faceRect); }
    ~FaceGeometry() = default;
    FaceGeometry &operator = (const FaceGeometry &other) = default;

    EyeLine eyeLine() const { return mEyeLine; }
    int eyeDistance() const { return mEyeDistance; }
    int halfEye() const { return mHalfEye; }
    QQPoint eyeCenter() const { return mEyeCenter; }
    QQPoint faceCenter() const { return mFaceCenter; }
    bool isNull() const { return eyeLine().isNull();}

    QQPoint lipCenter() const { return smLipCenterPt * eyeDistance() + faceCenter(); }
    QQPoint chinCenter() const { return smLipCenterPt * eyeDistance() + faceCenter(); }
    QQPoint lowerFace() const { return smLowerFacePt * eyeDistance() + faceCenter(); }
    QQPoint neckPoint() const { return smNeckPt * eyeDistance() + faceCenter(); }
    SCRect eyeBox() const { return SCRect(eyeDistance(), eyeCenter()); }
    SCRect noseBox() const { return SCRect(QQSize(halfEye(), eyeDistance()),
                                           faceCenter() + QQPoint(0, - halfEye() / 2)); }
    SCRect faceBox() const { return SCRect(2 * eyeDistance(), faceCenter()); }
    SCRect tightFace() const { return SCRect(2 * eyeDistance(), faceCenter() + QQPoint(0, halfEye())); }
    SCRect fullFace() const { return SCRect(3 * halfEye(), faceCenter() + QQPoint(0, halfEye())); }
    SCRect head() const { return SCRect(QQSize(3 * halfEye(), 2 * eyeDistance()), eyeCenter()); }
    FaceTypeRect ftRect(const ObjectType fotype=ObjectType::FaceFrontalFull);

    Rational expectedEyeWidth() const;

    void set(const EyeLine eline);
    void set(const FaceTypeRect &ftrect);
    void setTightFace(const SCRect tface);
    void setFullFace(const SCRect fface);
    void setHeadRect(const SCRect hrect);

    QStringList toDumpStrings() const;

public: // static
    static EyeLine expectedEyeLine(const FaceTypeRect ftrect, const bool adjusted=false);
    //static EyeROI eyeROI(const SCRect &frect) { return EyeROI(frect); }

private:
    EyeLine mEyeLine;
//    EyeROI mEyeROI;
    int mEyeDistance=0;
    int mHalfEye=0;
    QQPoint mEyeCenter;
    QQPoint mFaceCenter;
    FaceTypeRect mFTRect;

private: // static
    static QQPointF smLipCenterPt;
    static QQPointF smChinCenterPt;
    static QQPointF smLowerFacePt; // AKA Adam's Apple
    static QQPointF smNeckPt;
};


Q_DECLARE_METATYPE(FaceGeometry);

extern IFGEOMETRY_EXPORT QDebug operator << (QDebug dbg, const FaceGeometry &fgeom);
