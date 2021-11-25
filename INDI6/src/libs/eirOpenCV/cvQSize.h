#pragma once
#include "eirOpenCV.h"

#include <QSize>

#include <opencv2/core/types.hpp>

#include <cvSize.h>

class EIROPENCV_EXPORT cvQSize : public QSize
{
public:
    cvQSize() {;}
    cvQSize(const QSize other) : QSize(other) {;}
    cvQSize(const cvSize cvsz) : QSize(cvsz.width, cvsz.height) {;}
    operator cvSize () const { return cv::Size(width(), height()); }
};

