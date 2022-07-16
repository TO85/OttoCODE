//! \file ImagePakGeneratorInteface.h Plugin Interface for generating images used in the ImagePak class
#pragma once
#include "ocImage.h"

#include <Color>
#include <Ident>
#include <FloatQImage>
#include <FloatImagePlane>
#include <Image>


#include "ImagePak.h"

class OCIMAGE_EXPORT ImageGeneratorInterface
{
public:
    virtual ~ImageGeneratorInterface() {;}
    virtual Ident pluginIdent() const = 0;
    virtual Color::ComponentList supportedComponents() const = 0;
    virtual Image::TypeList supportedImageTypes() const = 0;
    virtual Image::TypeList supportedPixmapTypes() const = 0;
    virtual Color::ComponentList requiredComponents(const Color::Component coco) const = 0;
    virtual Color::ComponentList requiredComponents(const Image::Type itype) const = 0;
    virtual FloatQImage generateColorQImage(ImagePak & ipak, const Image::Type itype) const = 0;
    virtual FloatQImage generateFloatQImage(ImagePak & ipak, const Image::Type itype) const = 0;
    virtual FloatImagePlane generateFloatImagePlane(ImagePak & ipak, const Image::Type itype) const = 0;
    virtual QPixmap generatePixmap(const Image::Type &itype) const = 0;
};

#define ImageGeneratorInterfaceIID "EclipseRD.pluginIID.ImageGenerator.QImageBuiltin"

Q_DECLARE_INTERFACE(ImageGeneratorInterface, ImageGeneratorInterfaceIID)
