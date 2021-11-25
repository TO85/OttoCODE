#pragma once
#include "eirOpenCV.h"

#include <QtCore/QMetaType>

#include <opencv2/core/types.hpp>

#include <eirType/QQRect.h>
#include <eirType/SCRect.h>

#include "cvPoint.h"
#include "cvQSize.h"
#include "cvSize.h"

class EIROPENCV_EXPORT cvRect : public cv::Rect
{
public:
    typedef std::vector<cv::Rect> StdVector;

public:
    cvRect() = default;
    cvRect(const cv::Rect other) : cv::Rect(other) {;}
    cvRect(const cvRect &other) = default;
    cvRect(const QRect qrc) : cv::Rect(cvPoint(qrc.topLeft()), cvSize(qrc.size())) {;}
    ~cvRect() = default;
    cvRect &operator=(const cvRect &other) = default;
    QRect toQRect() const { return QRect(QPoint(x, y), QSize(width, height)); }
    QQRect toRect() const { return QQRect(QQPoint(QPoint(x, y)), QQSize(width, height)); }
    operator QRect () const { return toQRect(); }
    operator SCRect () const { return SCRect(toQRect()); }
    cvSize size() const { return cv::Rect::size(); }
    cvPoint topLeft() const { return cv::Rect::tl(); }
    cvPoint bottomRight() const { return cv::Rect::br(); }
    cvPoint center() const { return topLeft() + (size() / 2); }
    QString toString() const;
    operator QString() const { return toString(); }
};

Q_DECLARE_METATYPE(cvRect);

extern EIROPENCV_EXPORT QDebug operator<<(QDebug dbg, const cvRect &cvrc);
