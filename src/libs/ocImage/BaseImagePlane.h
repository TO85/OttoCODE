#pragma once

#include "BaseImage.h"
#include "BaseColorTable.h"

class BaseImagePlane : public BaseImage
{
public:
    BaseImagePlane() {;}
    BaseImagePlane(const BaseColorTable & ct);
    BaseImagePlane(const QImage & qimg, const BaseColorTable & ct);
    BaseColorTable colorTable() const { return mColorTable; }
    BaseColorTable & colorTable() { return mColorTable; }

public:

public: // static
    BaseImage::Format planeFormat() { return BaseImage::Format_Indexed8; }

private:
    BaseColorTable mColorTable;
};

