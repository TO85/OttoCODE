#include "Image.h"

Image::Image(QObject *parent) : QObject{parent} {;}

/* ------------------ static ---------------------- */

bool Image::isQImageType(const Type itype)
{
    return itype > $begQImages && itype < $endQImages;
}

bool Image::isFloatImageType(const Type itype)
{
    return itype > $begFloatImages && itype < $endFloatImages;
}

bool Image::isFloatPlaneType(const Type itype)
{
    return itype > $begFloatPlanes && itype < $endFloatPlanes;
}
