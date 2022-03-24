#include "ImagePak.h"

#include <QVariant>

#include <QQDir>
#include <QQString>

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

QImage ImagePak::qimage(const Image::Type ix) const
{
    return VariablePak::get(ix).vari().value<QImage>();
}

void ImagePak::set(const QQFileInfo &fi)
{
    VariablePak::set(Key("/Input/Directory"), QVariant(fi.absolutePath()));
    VariablePak::set(Key("/Input/FileName"), QVariant(fi.fileName()));
}

void ImagePak::set(const QByteArray &imageBytes)
{
    VariablePak::set(imageBytes);
}

void ImagePak::set(const Image::Type ix, const QImage &qi)
{
    QVariant tVari = qi;
    VariablePak::set(ix, tVari);
}

void ImagePak::load(const QQFileInfo &fi)
{
    set(fi);
    if (readImageFile())
        load(imageBytes());
}

void ImagePak::load(const QByteArray &imageData)
{
    set(imageData);
    if (loadOriginalImage())
        load();
}

void ImagePak::load()
{
    QImage tOriginal = qimage(Image::OriginalQImage);
    if (tOriginal.isNull()) return;                                     /* /====\ */
    set(Image::ColorQImage, tOriginal.convertToFormat(colorQFormat()));
    set(Image::FloatColorQImage, tOriginal.convertToFormat(floatQFormat()));
    set(Image::GreyQImage, tOriginal.convertToFormat(greyQFormat()));
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

bool ImagePak::generate(const Image::Type ix)
{
    if (Image::isQImageType(ix)) return generateQImage(ix);
    if (Image::isFloatImageType(ix)) return generateFloatImage(ix);
    if (Image::isFloatPlaneType(ix)) return generateFloatPlane(ix);
    return false;
}

bool ImagePak::generateQImage(const Image::Type ix)
{
    Q_UNUSED(ix); Q_ASSERT(false); // MUSTDO it
}

bool ImagePak::generateFloatImage(const Image::Type ix)
{
    Q_UNUSED(ix); Q_ASSERT(false); // MUSTDO it
}

bool ImagePak::generateFloatPlane(const Image::Type ix)
{
    Q_UNUSED(ix); Q_ASSERT(false); // MUSTDO it
}

bool ImagePak::readImageFile()
{
    QByteArray tBytes;
    if (fileInfo().exists() && fileInfo().isReadable())
    {
        QFile tFile(fileInfo().filePath());
        if (tFile.open(QIODevice::ReadOnly))
            tBytes = tFile.readAll();
    }
    set(tBytes);
    return ! imageBytes().isEmpty();
}

bool ImagePak::loadOriginalImage()
{
    QImage tImage;
    tImage.loadFromData(bytes());
    set(Image::OriginalQImage, tImage);
    return ! qimage(Image::OriginalQImage).isNull();
}

