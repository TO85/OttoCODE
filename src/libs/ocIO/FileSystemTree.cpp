#include "FileSystemTree.h"

#include <QMap>

#include <Sortable>

#include "DirectoryTreeEntry.h"
#include "DirectoryInfo.h"
#include "FileTreeEntry.h"

class FileSystemTreeData : public QSharedData
{
public:
    DirectoryInfo rootDirectory;
    QMap<Sortable, FileTreeEntry> mSortFileEntryMap;
    QMap<Sortable, DirectoryTreeEntry> mSortDirEntryMap;
};

FileSystemTree::FileSystemTree() : data(new FileSystemTreeData)
{

}

FileSystemTree::FileSystemTree(const FileSystemTree &rhs)
    : data{rhs.data}
{

}

FileSystemTree &FileSystemTree::operator=(const FileSystemTree &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

FileSystemTree::~FileSystemTree()
{

}

DirectoryInfo FileSystemTree::rootPath() const
{
    return data->rootDirectory;
}

DirectoryInfo FileSystemTree::rootPath(const DirectoryInfo &rootDir)
{
    return data->rootDirectory = rootDir;
}

DirectoryInfo FileSystemTree::rootPath(const QQString &pathName)
{

}

DirectoryInfo FileSystemTree::rootPath(const QDir &qdir)
{

}
