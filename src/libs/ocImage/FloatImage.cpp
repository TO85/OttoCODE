#include "FloatImage.h"

class FloatImageData : public QSharedData
{
public:
    Key dmKey;
};

FloatImage::FloatImage() : data(new FloatImageData) {;}
FloatImage::~FloatImage() {;}
FloatImage::FloatImage(const FloatImage &other) : data{other.data} {;}

FloatImage &FloatImage::operator=(const FloatImage &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

