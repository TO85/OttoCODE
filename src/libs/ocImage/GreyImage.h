#pragma once

#include "BaseImagePlane.h"

class GreyImage : public BaseImage
{
public:
    GreyImage();
    GreyImage(const QImage qimg);

public: // static
    BaseImage::Format greyFormat() { return BaseImage::Format_Grayscale8; }

};

