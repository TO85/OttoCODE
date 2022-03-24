#include "TrollImageGeneratorBuiltin.h"


TrollImageGeneratorBuiltin::TrollImageGeneratorBuiltin(QObject *parent) : QObject{parent} {;}

Ident TrollImageGeneratorBuiltin::pluginIdent() const
{
    Ident result;
    result.set(Uid());
    result.key("Plugin/ImageGenerator/QImageGeneratorBuiltin");
    return result;
}

Color::ComponentList TrollImageGeneratorBuiltin::supportedComponents() const
{
    Color::ComponentList result = Color::ComponentList()
            << Color::Alpha << Color::Opacity << Color::Tranparency
            << Color::Red << Color::Green << Color::Blue
            << Color::Hue << Color::Saturation << Color::Grey;
    return result;
}

Image::TypeList TrollImageGeneratorBuiltin::supportedImageTypes() const
{
    Image::TypeList result = Image::TypeList()
            << Image::ColorQImage << Image::GreyQImage << Image::FloatColorQImage;
    return result;
}

Image::TypeList TrollImageGeneratorBuiltin::supportedPixmapTypes() const
{
    Image::TypeList result = Image::TypeList()
            << Image::ColorQImage << Image::GreyQImage << Image::FloatColorQImage;
    return result;
}
