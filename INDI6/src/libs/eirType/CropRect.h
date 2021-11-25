#pragma once
#include "eirType.h"

#include <QRect>

class EIRTYPE_EXPORT CropRect : public QRect
{
public:
    CropRect() {;}
    CropRect(const QRect inrc, const unsigned clip=16);
};

