#include "cvMatType.h"

#include <eirXfr/Debug.h>

#include <QtCore/QString>

QImage::Format cvMatType::toQImageFormat() const
{
    switch (mType)
    {
    case Grey8Type:     return QImage::Format_Grayscale8;
    case BGRA32Type:    return QImage::Format_RGBA8888;
    default:            WARN << "Unhanled cvMatType:" << mType;
                        Q_FALLTHROUGH();
    case $nullType:     return QImage::Format_Invalid;
    }
}

bool cvMatType::set(const int itype)
{
    switch (itype)
    {
    case $nullType:
    case Grey8Type:
    case BGRA32Type:
        mType = itype;
        return true;

    default:
        RMUSTDO("Unhandled cvMatType: " + QString::number(itype));
        mType = $nullType;
        return false;
    }
}

cvMatType cvMatType::fromQImage(const QImage &qi)
{
    switch (qi.format())
    {
    case QImage::Format_Grayscale8:                                 return Grey8Type;
    case QImage::Format_RGBA8888:
    case QImage::Format_RGBA8888_Premultiplied:                       return BGRA32Type;
    default:    WARN << "Unhandled QImage::Format" << qi.format();  return $nullType;
    }
}


