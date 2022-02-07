#include "FileSystemTree.h"

#include <QFileInfo>
#include <QMap>

#include <QQFileInfo>
#include <QQDir>
#include <Sortable>
#include <SortableMap>

class FileSystemTreeData : public QSharedData
{
public:
    QQDir dmRootDir;
    SortableMap<QQFileInfo> dmSortFileMap;
    SortableMap<QQDir> dmSortDirMap;
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

/* ----------------------- generated -------------------------- */

QQDir FileSystemTree::rootDir() const
{
    return data ? data->dmRootDir : QQDir();
}

QQDir FileSystemTree::rootDir(const String &pathName)
{
    return rootDir(QQDir(pathName));
}

QQDir FileSystemTree::rootDir(const QDir &qdir)
{
    if (data) data->dmRootDir = qdir;
    return rootDir();
}

int FileSystemTree::fileCount() const
{
    return data ? data->dmSortFileMap.count() : -1;
}

int FileSystemTree::dirCount() const
{
    return data ? data->dmSortDirMap.count() : -1;
}

List<QQFileInfo> FileSystemTree::fileEntryList() const
{
    return data ? data->dmSortFileMap.values() : List<QQFileInfo>();
}

List<QQDir> FileSystemTree::dirEntryList() const
{
    return data ? data->dmSortDirMap.values() : List<QQDir>();
}

int FileSystemTree::add(QFileInfo fi)
{

}

int FileSystemTree::add(QQDir dir)
{

}
