#include "cvQStringList.h"

cvQStringList::cvQStringList(const std::list<cv::String> cvStringStdList)
{
    for (const cv::String &cvs : cvStringStdList)
        append(cvQString(cvs));
}

cvQStringList::cvQStringList(const cv::String &cvEndlString)
{
    for (auto &qs : cvQString(cvEndlString).split(QChar('\n')))
        append(qs);
}

cvQStringList::operator std::list<cv::String>() const
{
    std::list<cv::String> cvsl;
    for(auto &qs : *this)
        cvsl.push_back(cvString(qs));
    return cvsl;
}
