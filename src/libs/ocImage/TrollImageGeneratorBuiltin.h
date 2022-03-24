#pragma once
#include "ocImage.h"

#include <QObject>
#include "ImageGeneratorInterface.h"

#include <QPixmap>


class OCIMAGE_EXPORT TrollImageGeneratorBuiltin : public QObject, public ImageGeneratorInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ImageGeneratorInterfaceIID) // TODO FILE "QImageBuiltin.json")
    Q_INTERFACES(ImageGeneratorInterface)

public:
    virtual Ident pluginIdent() const override;
    virtual Color::ComponentList supportedComponents() const override;
    virtual Image::TypeList supportedImageTypes() const override;
    virtual Image::TypeList supportedPixmapTypes() const override;
    virtual Color::ComponentList requiredComponents(const Color::Component coco) const override {;}
    virtual Color::ComponentList requiredComponents(const Image::Type itype) const override {;}
    virtual FloatImage generateQImageImage(const ImagePak & ipak, const Image::Type itype) const override {;}
    virtual FloatImage generateFloatImage(const ImagePak & ipak, const Image::Type itype) const override {;}
    virtual FloatImagePlane generateFloatImagePlane(const ImagePak & ipak, const Image::Type itype) const override {;}
    virtual QPixmap generatePixmap(const Image::Type &itype) const override {;}

public:
    explicit TrollImageGeneratorBuiltin(QObject *parent = nullptr);

signals:

};

