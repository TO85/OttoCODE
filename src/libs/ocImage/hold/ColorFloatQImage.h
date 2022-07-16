#pragma once

#include <QImage>

#include <QMetaType>

class ColorFloatQImage : public QImage
{
public:
    ColorFloatQImage(const QImage other);

public:
    QImage set(const QImage other);


public: // QMetaType
    ColorFloatQImage() = default;
    ~ColorFloatQImage() = default;
    ColorFloatQImage(const ColorFloatQImage &other) = default;
    ColorFloatQImage &operator = (const ColorFloatQImage &other) = default;
};

Q_DECLARE_METATYPE(ColorFloatQImage);
