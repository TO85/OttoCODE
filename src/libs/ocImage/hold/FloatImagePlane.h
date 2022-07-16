#pragma once
#include "ocImage.h"

#include <QMetaType>

#include <Matrix2D>
#include <Pixel>

class OCIMAGE_EXPORT FloatImagePlane : public Matrix2D<ImageFloatType>
{
public:
    FloatImagePlane(const QImage &qimage, const Pixel::Mask mask);

public:

public:
    void set(const QImage &qimage, const Pixel::Mask mask);

private:

public:
  FloatImagePlane() = default;
  FloatImagePlane(const FloatImagePlane &other) = default;
  FloatImagePlane &operator=(const FloatImagePlane &rhs) = default;
  ~FloatImagePlane() = default;
};


Q_DECLARE_METATYPE(FloatImagePlane);

