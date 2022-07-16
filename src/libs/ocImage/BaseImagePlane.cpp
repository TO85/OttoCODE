#include "BaseImagePlane.h"

BaseImagePlane::BaseImagePlane(const BaseColorTable &ct) : mColorTable(ct) {;}
BaseImagePlane::BaseImagePlane(const QImage &qimg, const BaseColorTable &ct)
    : BaseImage(qimg.convertedTo(planeFormat())), mColorTable(ct) {;}
