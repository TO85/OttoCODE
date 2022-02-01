#include "DirectoryInfo.h"

#include <QQString>

class DirectoryInfoData : public QSharedData
{
public:
    QQString directoryPath;
};

DirectoryInfo::DirectoryInfo() : data(new DirectoryInfoData)
{

}

DirectoryInfo::DirectoryInfo(const DirectoryInfo &rhs)
    : data{rhs.data}
{

}

DirectoryInfo &DirectoryInfo::operator=(const DirectoryInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

DirectoryInfo::~DirectoryInfo()
{

}
