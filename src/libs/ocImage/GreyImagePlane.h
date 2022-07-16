#pragma once

#include "BaseImagePlane.h"

#include "GreyImage.h"

class GreyImagePlane : public BaseImagePlane
{
public:
    GreyImagePlane();
    GreyImagePlane(const GreyImage & greyimg);
};

