#include "ColorQImage.h"

#include <QByteArray>
#include <QFile>
#include <QIODevice>

#include "ImagePak.h"

ColorQImage::ColorQImage(const QString &fileName, const char *format)
    : QImage(fileName, format)
{

}

ColorQImage::ColorQImage(const QQFileInfo &fi)
{
    set(fi);
}

ColorQImage::ColorQImage(const QImage &other)
{
    set(other);
}

QImage ColorQImage::set(const QQFileInfo &fi)
{
    QImage result;
    if (fi.exists() && fi.isReadable())
    {
        QFile * pFile = new QFile(fi.filePath());
        if (pFile->open(QIODevice::ReadOnly))
        {
            QByteArray tBytes = pFile->readAll();
            pFile->close();
            pFile->deleteLater();
            return set(tBytes);                                         /* /====\ */
        }
    }
    return result;
}

QImage ColorQImage::set(const QByteArray &bytes)
{
    QImage result;
    if ( ! bytes.isEmpty())
        result.loadFromData(bytes);
    return result.isNull() ? result : set(result);
}

QImage ColorQImage::set(const QImage &other)
{
    QImage result(other);
    result.convertTo(ImagePak::colorQFormat());
    return result;
}

