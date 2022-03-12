#pragma once
#include "ocImage.h"

#include <QMetaType>


class OCIMAGE_EXPORT FloatImage
{
public:


public:
    FloatImage() = default;
    ~FloatImage() = default;
    FloatImage(const FloatImage &other) = default;
    FloatImage &operator=(const FloatImage & rhs) = default;
};


Q_DECLARE_METATYPE(FloatImage);

