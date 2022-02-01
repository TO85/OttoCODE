#include "FileSystemObject.h"

#include "DirectoryInfo.h"

FileSystemObject::FileSystemObject(QObject *parent)
    : QObject{parent}
{

}

FileSystemObject::FileSystemObject(const QQString &rootPath, QObject *parent)
{
    mTree.rootPath(rootPath);
}
