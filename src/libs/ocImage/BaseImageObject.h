#pragma once

#include <QObject>

#include "BaseImage.h"
#include "ColorImage.h"
#include "GreyImage.h"

class BaseImageObject : public QObject
{
    Q_OBJECT
public:
    explicit BaseImageObject(QObject *parent = nullptr);

signals:

protected:
    BaseImage mInputImage;
    ColorImage mColorImage;
    GreyImage mGreyImage;
};

