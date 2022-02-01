#pragma once

#include <QSharedDataPointer>

class DirectoryInfoData;

class DirectoryInfo
{
public:
    DirectoryInfo();
    DirectoryInfo(const DirectoryInfo &);
    DirectoryInfo &operator=(const DirectoryInfo &);
    ~DirectoryInfo();

private:
    QSharedDataPointer<DirectoryInfoData> data;
};

