#pragma once
#include "eirOpenCV.h"

#include <QImage>

class cvMat;

class EIROPENCV_EXPORT cvMatQImage : public QImage
{
public:
    cvMatQImage() {;}
    cvMatQImage(const cvMat &mat, const QImage::Format qif=QImage::Format_Invalid);
};

