#include "FileSystemTree.h"

#include <QMap>

class FileSystemTreeData : public QSharedData
{
public:
    QQDir dmRootDir;
    QMap<QQString, QQFileInfo> dmFileNameInfoMap;
    QMap<QQString, QQDir> dmPathNameDirMap;
    QMap<QQDir, QQFileInfoList> dmDirFileInfoListMap;
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

QQDir FileSystemTree::rootDir(const QQString &pathName)
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
    return data ? data->dmFileNameInfoMap.count() : -1;
}

int FileSystemTree::dirCount() const
{
    return data ? data->dmPathNameDirMap.count() : -1;
}

QList<QQFileInfo> FileSystemTree::fileEntryList() const
{
    return data ? data->dmFileNameInfoMap.values() : QList<QQFileInfo>();
}

QList<QQDir> FileSystemTree::dirEntryList() const
{
    return data ? data->dmPathNameDirMap.values() : QList<QQDir>();
}

int FileSystemTree::add(QFileInfo fi)
{
    Q_ASSERT(false); // MUSTDO
    Q_UNUSED(fi);
    return -1;
}

int FileSystemTree::add(QQDir dir)
{
    Q_ASSERT(data);
    data->dmPathNameDirMap.insert(dir.path(), dir);
    data->dmDirFileInfoListMap.insert(dir, QQFileInfoList());
    return data->dmPathNameDirMap.count();
}
