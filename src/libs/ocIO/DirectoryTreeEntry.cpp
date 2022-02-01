#include "DirectoryTreeEntry.h"

class DirectoryTreeEntryData : public QSharedData
{
public:

};

DirectoryTreeEntry::DirectoryTreeEntry() : data(new DirectoryTreeEntryData)
{

}

DirectoryTreeEntry::DirectoryTreeEntry(const DirectoryTreeEntry &rhs)
    : data{rhs.data}
{

}

DirectoryTreeEntry &DirectoryTreeEntry::operator=(const DirectoryTreeEntry &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

DirectoryTreeEntry::~DirectoryTreeEntry()
{

}
