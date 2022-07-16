#include "GreyImage.h"

GreyImage::GreyImage() {;}
GreyImage::GreyImage(const QImage qimg) : BaseImage(qimg.convertedTo(greyFormat())) {;}

