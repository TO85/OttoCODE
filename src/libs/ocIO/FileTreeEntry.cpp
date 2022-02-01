#include "FileTreeEntry.h"

class FileTreeEntryData : public QSharedData
{
public:

};

FileTreeEntry::FileTreeEntry() : data(new FileTreeEntryData)
{

}

FileTreeEntry::FileTreeEntry(const FileTreeEntry &rhs)
    : data{rhs.data}
{

}

FileTreeEntry &FileTreeEntry::operator=(const FileTreeEntry &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

FileTreeEntry::~FileTreeEntry()
{

}
