#pragma once
#include "eirOpenCV.h"

#include <QtCore/QMetaType>

#include <opencv2/highgui.hpp>

#include <eirType/MultiName.h>

#include <eirGui/QQImage.h>

#include "cvMatType.h"

class EIROPENCV_EXPORT cvHighGui
{
public:
    cvHighGui() = default;
    cvHighGui(const cvHighGui &other) = default;
    ~cvHighGui() = default;
    cvHighGui &operator = (const cvHighGui &other) = default;

    bool imshow(const QQImage &aImage, const cvMatType aMatType=cvMatType::BGRA32(),
                const int waitMsec=5000, const QQString &aName=QQString()) const;
};

Q_DECLARE_METATYPE(cvHighGui);
