#pragma once
#include "ocImage.h"

#include <Key>

class FloatImageData;

class OCIMAGE_EXPORT FloatImage
{
public:
    FloatImage();
    ~FloatImage();
    FloatImage(const FloatImage &);
    FloatImage &operator=(const FloatImage &);

public:
    Key key() const;

private:
    QSharedDataPointer<FloatImageData> data;

};


Q_DECLARE_METATYPE(FloatImage);

