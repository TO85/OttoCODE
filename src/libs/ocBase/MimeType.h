#pragma once

#include <QObject>

class MimeType : public QObject
{
    Q_GADGET
public:
    enum Type
    {
        $nullType               = 0,
        $beginImage             = 100,
        ImageBmp,                   // BMP  Windows Bitmap
        ImageGif,                   // GIF  Graphic Interchange Format
        ImageJpeg,                  // JPG  Joint Photographic Experts Group
        ImagePng,                   // PNG  Portable Network Graphics
        ImageXPortableBitmap,       // PBM  Portable Bitmap
        ImageXPortableGraymap,      // PGM  Portanle Greymap
        ImageXPortablePixmap,       // PPM  Portable Pixmap
        ImageXXBitmap,              // XBM  X11 Bitmap
        ImageXXPixmap,              // XPM  X11 Pixmap
        ImageSvgXml,                // SVG  Scalable Vector Graphics
        $endImage,
        $maxType
    };
    Q_ENUM(Type);

public:
    explicit MimeType(QObject *parent = nullptr);

signals:

};

