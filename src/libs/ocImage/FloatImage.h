#pragma once
#include "ocImage.h"


#include <QMetaType>


class FloatImage
{
public:
    FloatImage(const QImage &qi);

public:
    FloatImage() = default;
    ~FloatImage() = default;
    FloatImage(const FloatImage &other) = default;
    FloatImage &operator = (const FloatImage &other) = default;

};

Q_DECLARE_METATYPE(FloatImage);

