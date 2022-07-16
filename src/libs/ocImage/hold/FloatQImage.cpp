#include "FloatQImage.h"

#include "ImagePak.h"

FloatQImage::FloatQImage(const QString &fileName, const char *format)
    : QImage(fileName, format)
{
    convertTo(ImagePak::floatQFormat());
}

FloatQImage::FloatQImage(const QQFileInfo &fi)
{
    set(fi);
}

FloatQImage::FloatQImage(const QImage &other)
{
    set(other);
}

QImage FloatQImage::set(const QQFileInfo &fi)
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

QImage FloatQImage::set(const QByteArray &bytes)
{
    QImage result;
    if ( ! bytes.isEmpty())
        result.loadFromData(bytes);
    return result.isNull() ? result : set(result);
}

QImage FloatQImage::set(const QImage &other)
{
    QImage result(other);
    result.convertTo(ImagePak::floatQFormat());
    swap(result);
    return it();
}
