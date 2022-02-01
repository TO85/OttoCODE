#pragma once

class FileTreeEntryData;

#include <QSharedDataPointer>

#include <List>


class FileTreeEntry
{
public:
    FileTreeEntry();
    FileTreeEntry(const FileTreeEntry &);
    FileTreeEntry &operator=(const FileTreeEntry &);
    ~FileTreeEntry();

private:
    QSharedDataPointer<FileTreeEntryData> data;
};

