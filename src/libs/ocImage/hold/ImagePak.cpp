#include "ImagePak.h"

#include <QPixmap>
#include <QVariant>

#include <QQDir>
#include <QQFile>
#include <QQString>

#include "ColorQImage.h"

ImagePak::ImagePak() {;}
ImagePak::ImagePak(const int variantReserve) : VariablePak(variantReserve, 0) {;}
ImagePak::ImagePak(const QQFileInfo &fileInfo) { set(fileInfo); }

QQFileInfo ImagePak::fileInfo() const
{
    QQString tPathName = get("Input/Directory").vari().toString();
    QQString tFileName = get("Input/FileName").vari().toString();
    return QQFileInfo(QQDir(tPathName), tFileName);
}

QByteArray ImagePak::imageBytes() const
{
    return VariablePak::bytes();
}

bool ImagePak::contains(const Image::Type ix) const
{
    return VariablePak::get(ix).notNull();
}

Size ImagePak::size() const
{
    return Size(original().size());
}

void ImagePak::set(const QQFileInfo &fileInfo)
{
    VariablePak::set(Key("/Input/Directory"), QVariant(fileInfo.absolutePath()));
    VariablePak::set(Key("/Input/FileName"), QVariant(fileInfo.fileName()));
    set(QQFile::readFile(fileInfo));
}

void ImagePak::set(const QByteArray &imageBytes)
{
    VariablePak::set(imageBytes);
    QImage tImage = QImage::fromData(imageBytes);
    set(tImage);
}

void ImagePak::set(const QImage &originalImage)
{
    set(Image::OriginalQImage, originalImage);
}

void ImagePak::set(const Image::Type ix, const QImage &qi)
{
    QVariant tVari = qi;
    VariablePak::set(ix, tVari);
}

void ImagePak::set(const Image::Type ix, const FloatQImage &fi)
{
    Q_UNUSED(ix); Q_UNUSED(fi); Q_ASSERT(false); // MUSTDO it

}

void ImagePak::set(const Image::Type ix, const FloatImagePlane &fip)
{
    Q_UNUSED(ix); Q_UNUSED(fip); Q_ASSERT(false); // MUSTDO it

}

QImage ImagePak::original() const
{
    return getImage(Image::OriginalQImage);
}

QImage ImagePak::colorQImage(const Image::Type ix)
{
    QImage result;
    if (notValidIndex(ix)) return result;                           /* /====\ */
    if (Image::isQImageType(ix)) return result;                     /* /====\ */
    if (notContains(ix))
        generate(ix);
    result = variant(ix).value<QImage>();
    return result;
}

QImage ImagePak::getImage(const Image::Type ix) const
{
    QImage result;
    if (notValidIndex(ix)) return result;                           /* /====\ */
    if (Image::isQImageType(ix)) return result;                     /* /====\ */
    if (notContains(ix)) return result;                             /* /====\ */
    result = variant(ix).value<QImage>();
    return result;
}


/* ------------------ static ---------------------- */

QImage::Format ImagePak::colorQFormat()
{
    return QImage::Format_ARGB32_Premultiplied;
}

QImage::Format ImagePak::floatQFormat()
{
    return QImage::Format_RGBA32FPx4_Premultiplied;
}

QImage::Format ImagePak::greyQFormat()
{
    return QImage::Format_Grayscale8;
}

/* ------------------ protected ---------------------- */

void ImagePak::generate(const Image::Type ix)
{
    if (Image::isQImageType(ix))        generateQImage(ix);
    if (Image::isFloatQImageType(ix))   generateQFloatImage(ix);
    if (Image::isFloatPlaneType(ix))    generateFloatPlane(ix);
}

void ImagePak::generateQImage(const Image::Type ix)
{
    switch (ix)
    {
    case Image::OriginalQImage:     generateOriginal();     break;
    case Image::ColorQImage:        generateColorQI();      break;

    default:
        Q_ASSERT(false); // MUSTDO it
    }
}

void ImagePak::generateQFloatImage(const Image::Type ix)
{
    Q_UNUSED(ix); Q_ASSERT(false); // MUSTDO it
}

void ImagePak::generateFloatPlane(const Image::Type ix)
{
    Q_UNUSED(ix); Q_ASSERT(false); // MUSTDO it
}

void ImagePak::generateOriginal()
{
    const QQFileInfo tFI = fileInfo();
    if (tFI.exists() && tFI.isReadable())
    {
        const QQString tFileName = tFI.filePath();
        QImage tImage(tFileName);
        if (tImage.format() != ImagePak::colorQFormat())
            (void)tImage.convertToFormat(ImagePak::colorQFormat());
        set(Image::OriginalQImage, tImage);
    }
}

void ImagePak::generateColorQI()
{
    if (notContains(Image::OriginalQImage))
        generateOriginal();
    ColorQImage tCQI = original();
    set(Image::ColorQImage, tCQI);
}
