#include "ImageSupport.h"

#include <QtGui/QImageReader>
#include <QtGui/QImageWriter>
#include <eirXfr/Debug.h>


ImageSupport::FormatNames ImageSupport::supportedReaderFormats() const
{
    return QImageReader::supportedImageFormats();
}

QQByteArray ImageSupport::supportedReaderFormatString() const
{
    return supportedReaderFormats().join(' ');
}

ImageSupport::DirNameFilters ImageSupport::supportedReaderDirNameFilters() const
{
    DirNameFilters result;
    for (QQString extName : supportedReaderFormats())
        result << QQString("*.%1").arg(extName);
    return result;
}

ImageSupport::DirNameFilters ImageSupport::toDirNameFilters(const FormatNames aNames)
{
    DirNameFilters result;
    for (QQByteArray ba : aNames)
        result << ba;
    return result;
}

/* ---------------------- debug ------------------------ */
