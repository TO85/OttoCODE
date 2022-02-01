#include "FileInfo.h"

class FileInfoData : public QSharedData
{
public:

};

FileInfo::FileInfo() : data(new FileInfoData)
{

}

FileInfo::FileInfo(const FileInfo &rhs)
    : data{rhs.data}
{

}

FileInfo &FileInfo::operator=(const FileInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

FileInfo::~FileInfo()
{

}
