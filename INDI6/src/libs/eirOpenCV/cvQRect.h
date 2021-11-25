#pragma once
#include "eirOpenCV.h"

#include <QtCore/QMetaType>
#include <QtCore/QRect>

#include <opencv2/core/types.hpp>

#include <eirType/SCRect.h>

#include "cvPoint.h"
#include "cvRect.h"
#include "cvSize.h"

class EIROPENCV_EXPORT cvQRect : public QRect
{
public:
    cvQRect() = default;
    cvQRect(const cvQRect &other) = default;
    cvQRect(const QRect other) : QRect(other) {;}
    cvQRect(const cvRect cvrc) : QRect(cvrc.topLeft(), cvrc.size()) {;}
    ~cvQRect() = default;
    cvQRect &operator=(const cvQRect &other) = default;

    cvPoint topLeft() const { return QRect::topLeft(); }
    cvSize size() const { return QRect::size(); }
    SCRect toSCRect() const { return SCRect(size(), center()); }
    QString toString() const;
    operator cvRect () const { return cv::Rect(left(), top(), width(), height()); }
    operator QString() const { return toString(); }
};

Q_DECLARE_METATYPE(cvQRect);
