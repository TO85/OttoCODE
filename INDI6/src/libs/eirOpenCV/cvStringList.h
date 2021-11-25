#pragma once
#include "eirOpenCV.h"

#include <QStringList>

#include <opencv2/core/cvstd.hpp>

#include "cvQString.h"
#include "cvString.h"

class EIROPENCV_EXPORT cvStringList : public std::list<cv::String>
{
public:
    cvStringList() {;}
    cvStringList(const std::list<cv::String> other) : std::list<cv::String>(other) {;}
    cvStringList(const cv::String &cvEndlString)
    { for (auto &qs : cvQString(cvEndlString).split(QChar('\n'))) push_back(cvString(qs)); }
};

