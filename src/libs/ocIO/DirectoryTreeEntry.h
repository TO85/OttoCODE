#pragma once

#include <QSharedDataPointer>

#include <List>

class DirectoryTreeEntryData;

class DirectoryTreeEntry
{
public:
    DirectoryTreeEntry();
    DirectoryTreeEntry(const DirectoryTreeEntry &);
    DirectoryTreeEntry &operator=(const DirectoryTreeEntry &);
    ~DirectoryTreeEntry();

private:
    QSharedDataPointer<DirectoryTreeEntryData> data;
};

