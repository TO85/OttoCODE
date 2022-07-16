#include "ColorImage.h"

ColorImage::ColorImage() {;}
ColorImage::ColorImage(const QImage qimg) : BaseImage(qimg.convertedTo(colorFormat())) {;}
