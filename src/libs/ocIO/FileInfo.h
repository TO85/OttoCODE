#pragma once

#include <QSharedDataPointer>

class FileInfoData;

class FileInfo
{
public:
    FileInfo();
    FileInfo(const FileInfo &);
    FileInfo &operator=(const FileInfo &);
    ~FileInfo();

private:
    QSharedDataPointer<FileInfoData> data;
};

