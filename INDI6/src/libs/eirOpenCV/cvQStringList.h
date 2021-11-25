#pragma once
#include "eirOpenCV.h"

#include <QStringList>

#include <opencv2/core/cvstd.hpp>

#include "cvQString.h"
#include "cvString.h"

class EIROPENCV_EXPORT cvQStringList : public QStringList
{
public:
    cvQStringList(const QStringList &other) : QStringList(other) {;}
    cvQStringList(const std::list<cv::String> cvStringStdList);
    cvQStringList(const cv::String &cvEndlString);
    explicit cvQStringList() = default;
    cvQStringList(const cvQStringList &other) = default;
    ~cvQStringList() = default;
    cvQStringList &operator = (const cvQStringList &other) = default;

    operator std::list<cv::String> () const;

private:
    cvQStringList &it() { return *this; }
    cvQStringList it() const { return *this; }
};

Q_DECLARE_METATYPE(cvQStringList);
