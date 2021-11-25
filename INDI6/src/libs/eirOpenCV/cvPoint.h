#pragma once
#include "eirOpenCV.h"

#include <opencv2/core/types.hpp>

#include <QtCore/QPoint>

#include "cvSize.h"

class EIROPENCV_EXPORT cvPoint : public cv::Point
{
public:
    cvPoint() {;}
    cvPoint(const int x, const int y) : cv::Point(x, y) {;}
    cvPoint(const cv::Point &other) : cv::Point(other) {;}
    cvPoint(const QPoint qpt) : cv::Point(qpt.x(), qpt.y()) {;}
    int x() const { return cv::Point::x; }
    int y() const { return cv::Point::y; }
    int &x()  { return cv::Point::x; }
    int &y()  { return cv::Point::y; }
    cvPoint added(const cvPoint &other) const { return cvPoint(x() + other.x(), y() + other.y());}
    cvPoint added(const cvSize &cvsz) const { return cvPoint(x() + cvsz.width, y() + cvsz.height);}
    void add(const cvPoint &other) { x() = x() + other.x(); y() = y() + other.y(); }
    cvPoint divided(const int by) { return cvPoint(x() / by, y() / by); }
    cvPoint operator + (const cvPoint &other) { return added(other); }
    cvPoint operator + (const cvSize &cvsz) { return added(cvsz); }
    operator QPoint () const { return QPoint(x(), y()); }
};

