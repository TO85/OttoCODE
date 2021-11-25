#pragma once
#include "IfObject.h"

#include <eirType/DProperty.h>
#include <QtCore/QSharedDataPointer>

#include <QtDebug>
#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtGui/QImage>

#include <eirGui/QQImage.h>
#include <eirType/BasicName.h>
#include <IfGeometry/EyeROI.h>
#include <IfObject/ObjectResults.h>

#define FACEDATA_DATAPROPS(TND) \
    TND(ObjectResultItem, FaceResultItem, ObjectResultItem()) \
    TND(BasicName, RegionName, BasicName()) \
    TND(QQImage, CroppedFaceImage, QQImage()) \
    TND(QQImage, DetectFaceImage, QQImage()) \
    TND(QQImage, EyeMarkedFaceImage, QQImage()) \
    TND(QQImage, NormalizedFaceImage, QQImage()) \
    TND(QQImage, GeneratedFaceImage, QQImage()) \
    TND(EyeROI, EyeROI, EyeROI()) \
    TND(ObjectResults, RawEyeResults, ObjectResults()) \
    TND(ObjectResults, LeftEyeResults, ObjectResults()) \
    TND(ObjectResults, RightEyeResults, ObjectResults()) \

class FaceDataData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(FACEDATA_DATAPROPS)
public:
    FaceDataData(void)
    {
        DEFINE_DATAPROPS_CTORS(FACEDATA_DATAPROPS)
    }
};

class IFOBJECT_EXPORT FaceData
{
    DECLARE_PARENT_DATAPROPS(FACEDATA_DATAPROPS)
    DECLARE_DATAPROPS(FaceData, FaceDataData)
public:
    typedef QVector<FaceData> Vector;

public:
    QQStringList toDebugStrings() const;
};

extern IFOBJECT_EXPORT QDebug operator << (QDebug dbg, const FaceData face);

