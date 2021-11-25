#pragma once
#include "eirOpenCV.h"

#include <opencv2/core/cvstd.hpp>

#include <QtCore/QMetaType>
#include <QtCore/QString>

#include <eirType/QQString.h>

class EIROPENCV_EXPORT cvString : public cv::String
{
public:
    cvString(const QString &qs);
    cvString(const cv::String &other) : cv::String(other) {;}
    explicit cvString() = default;
    cvString(const cvString &other) = default;
    ~cvString() = default;
    cvString &operator = (const cvString &other) = default;

public:
    bool notEmpty() const { return size() > 0; }
    bool isEmpty() const { return ! notEmpty(); }
    QString toString() const;
    operator QString () const { return toString(); }

private:
    cvString it() const { return *this; }
    cvString &it() { return *this; }

public:
   QQString toDebugString() const;
};

Q_DECLARE_METATYPE(cvString);

extern EIROPENCV_EXPORT QDebug operator << (QDebug dbg, const cvString &cvs);

