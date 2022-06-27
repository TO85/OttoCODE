#pragma once

#include <QImage>

#include <QMap>

class FrameImage : public QImage
{
public:
    enum ColorPlane { $nullPlane = 0, Grey, Red, Green, Blue,
                      Hue, Saturation, Cyan, Magenta, Yellow,
                      Cr, Cb, U, V, I, Q, $sizePlane };
public:
    FrameImage();
    FrameImage(const QImage &qi);

public:
    QImage colorImage() const;
    QImage greyImage() const;
    QPixmap plane(const ColorPlane cp) const;

public:

public: // static
    static QImage::Format colorImageFormat() { return QImage::Format_BGR888; }
    static QImage::Format greyImageFormat() { return QImage::Format_Grayscale8; }

private:
    QPixmap generate(const ColorPlane cp) const;

private:
    QImage mColorImage;
    mutable QImage mGreyImage;
    mutable QMap<ColorPlane, QPixmap> mPlanePixmapMap;
};

