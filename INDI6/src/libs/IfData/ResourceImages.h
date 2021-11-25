#pragma once
#include "IfData.h"

#include <QtGui/QBitmap>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QColor>

#include <eirXfr/Debug.h>

#include "ResourceValues.h"
class ResourceBitMask;

class IFDATA_EXPORT ResourceImages
{
public:
    ResourceImages(const ResourceValues &aValues);
    const ResourceValues values() const { return cmValues; }

    // Bitmask
    QBitmap bitmap();
    QPixmap pixmap(const QColor trueColor=Qt::lightGray,
                   const QColor falseColor=Qt::darkGray,
                   const QColor eyeMarkColor=Qt::yellow);
    QImage maskImage(const QImage::Format format=QImage::Format_Indexed8,
                     const QColor trueColor=Qt::lightGray,
                     const QColor falseColor=Qt::darkGray,
                     const QColor eyeMarkColor=Qt::yellow);

    // FLoatVector
    QPixmap pixmap(const ResourceBitMask &mask,
                   const QColor lowColor=QColor(0x101010FF),
                   const QColor zeroColor=QColor(0x808080FF),
                   const QColor highColor=QColor(0xF0F0F0FF),
                   const QColor eyeMarkColor=Qt::yellow)
                   { MUSTRTN(QPixmap()); }
    QPixmap pixmap(const ResourceBitMask &mask,
                   const QColor lowColor=QColor(0x101010FF),
                   const QColor highColor=QColor(0xF0F0F0FF),
                   const QColor eyeMarkColor=Qt::yellow)
                   { MUSTRTN(QPixmap()); }
    QImage maskImage(const ResourceBitMask &mask,
                     const QImage::Format format=QImage::Format_Indexed8,
                     const QColor lowColor=QColor(0x101010FF),
                     const QColor zeroColor=QColor(0x808080FF),
                     const QColor highColor=QColor(0xF0F0F0FF),
                     const QColor eyeMarkColor=Qt::yellow)
                     { MUSTRTN(QImage()); }
    QImage maskImage(const ResourceBitMask &mask,
                     const QImage::Format format=QImage::Format_Indexed8,
                     const QColor lowColor=QColor(0x101010FF),
                     const QColor highColor=QColor(0xF0F0F0FF),
                     const QColor eyeMarkColor=Qt::yellow)
                     { MUSTRTN(QImage()); }

private:
    const ResourceValues cmValues;
};

