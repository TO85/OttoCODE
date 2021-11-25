#pragma once
#include "eirOpenCV.h"

#include <opencv2/core/types.hpp>

#include <QtCore/QSize>

#include <eirType/QQSize.h>

class EIROPENCV_EXPORT cvSize : public cv::Size
{
public:
    cvSize() {;}
    cvSize(const cv::Size &other) : cv::Size(other) {;}
    cvSize(const int w, const int h) { width = w, height = h; }
    cvSize(const QSize qsz) : cv::Size(qsz.width(), qsz.height()) {;}
    cvSize divided(const int by) { return cvSize(width / by, height / by); }
    cvSize operator / (const int by) { return divided(by); }
    operator QSize () const { return QSize(width, height); }
    operator QQSize () const { return QQSize(width, height); }
};

