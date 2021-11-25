#pragma once
#include "IfObject.h"
#include <eirType/DProperty.h>
#include <QtCore/QSharedDataPointer>

#include <QtCore/QString>
#include <QtGui/QImage>

#include <eirType/MultiName.h>
#include <eirGui/ImageSizeMap.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQSize.h>
#include <IfObject/ObjectResults.h>

//    TND(MultiName, Name, QString())

#define FRAMEDATA_DATAPROPS(TND) \
    TND(QString, Name, QString()) \
    TND(int, FaceCount, 0) \
    TND(QQFileInfo, FileInfo, QQFileInfo()) \
    TND(QQSize, InputImageSize, QQSize()) \
    TND(QImage, InputImage, QImage()) \
    TND(ObjectResults, FaceResults, ObjectResults()) \

class FrameDataData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(FRAMEDATA_DATAPROPS)
public:
    FrameDataData(void)
    {
        DEFINE_DATAPROPS_CTORS(FRAMEDATA_DATAPROPS)
    }
};

class IFOBJECT_EXPORT FrameData
{
    DECLARE_PARENT_DATAPROPS(FRAMEDATA_DATAPROPS)
    DECLARE_DATAPROPS(FrameData, FrameDataData)

public:
    void reset() { *this = FrameData(); }

private:
};

