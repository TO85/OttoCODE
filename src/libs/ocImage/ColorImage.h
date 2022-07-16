#pragma once

#include "BaseImage.h"

class ColorImage : public BaseImage
{
public:
    ColorImage();
    ColorImage(const QImage qimg);

public: // static
    BaseImage::Format colorFormat() { return BaseImage::Format_ARGB32; }
};

