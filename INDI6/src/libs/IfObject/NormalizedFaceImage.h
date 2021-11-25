#pragma once
#include "IfObject.h"

#include <eirGui/QQImage.h>

#include <QtCore/QMetaType>

#include <eirType/QQBitArray.h>
#include <eirType/QQSize.h>
#include <eirType/SCRect.h>
#include <eirGui/QQColor.h>
#include <eirGui/QQTransform.h>
#include <IfGeometry/EyeLine.h>
#include <IfGeometry/EyeLineF.h>

class IFOBJECT_EXPORT NormalizedFaceImage : public QQImage
{
public:
    NormalizedFaceImage() = default;
    NormalizedFaceImage(const QQImage &frameImage, const SCRect faceRect, const EyeLine eline)
    { set(frameImage, faceRect, eline); }
    NormalizedFaceImage(const NormalizedFaceImage &other) = default;
    ~NormalizedFaceImage() = default;
    NormalizedFaceImage &operator = (const NormalizedFaceImage &other) = default;

public:
    QQTransform transform() const { return mTransform; }
    QQImage masked(const QQBitArray &mask,
                   const bool toGrey=true,
                   const QQColor &maskColor=Qt::blue,
                   const QQColor &markColor=Qt::yellow);

public:
    QQImage set(const QQImage &aFrameImage, const SCRect aFaceRect, const EyeLine aEline);

public:
    static void setNormalGeometry(const QQSize aSize, const EyeLine aLine);

private:
    QQImage &it() { return *this; }
    QQImage it() const { return *this; }

private:
    void calculate();
    QQImage markCenterLines(const QQImage &aImage, const QQLine aLine=QQLine()) const;

private:
    QQImage mFrameImage;
    SCRect mFaceRect;
    EyeLine mEyeLine;
    QQTransform mTransform;
    static QQSize smNormalSize;
    static EyeLine smNormalEyeLine;
};

Q_DECLARE_METATYPE(NormalizedFaceImage);
