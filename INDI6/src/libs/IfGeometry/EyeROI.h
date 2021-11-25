#pragma once
#include "IfGeometry.h"

#include <QtCore/QMetaType>

#include <eirType/DetectRect.h>
#include <eirType/SCRect.h>
#include <IfObject/ObjectResults.h>

class IFGEOMETRY_EXPORT EyeROI
{
public:
    EyeROI() = default;
    EyeROI(const SCRect aFaceRect) { set(aFaceRect); }
    EyeROI(const QVariant &vari);
    EyeROI(const EyeROI &other) = default;
    ~EyeROI() = default;
    EyeROI &operator = (const EyeROI &other) = default;

    SCRect left() const { return mLeftRect; }
    SCRect right() const { return mRightRect; }
    SCRect faceRect() const { return mFaceRect; }
    QVariant toVariant() const;
    operator QVariant () const { return toVariant(); }
    int distance() const { return eyeLine().distance(); }
    ObjectType classify(const DetectRect &eyeDR, const QQPoint offset=QQPoint(0,0)) const;
    EyeLine eyeLine() const { return EyeLine(left().center(), right().center()); }

    void set(const SCRect &frect);
    static EyeLine parseEyeLine(const DetectRectList &aEyeDetectList);

    QString toDebugString() const;

private:
    void set(const SCRect lRect, const SCRect rRect) { mLeftRect = lRect, mRightRect = rRect; }
    ObjectType byDistance(const QQPoint pt) const;
    EyeROI it() const { return *this; }
    EyeROI &it() { return *this; }

private:
    SCRect mLeftRect;
    SCRect mRightRect;
    SCRect mFaceRect;
    static SCRectF smLeyeRectF; //(QQSizeF(0.5, 0.5), QQPointF(-0.25, -0.125));
    static SCRectF smReyeRectF; //(QQSizeF(0.5, 0.5), QQPointF(+0.25, -0.125));
};

Q_DECLARE_METATYPE(EyeROI);

extern IFGEOMETRY_EXPORT QDebug operator << (QDebug dbg, const EyeROI &roi);
