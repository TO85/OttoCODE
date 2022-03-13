#pragma once
#include "ocIO.h"

#include <QSharedDataPointer>
class FileSystemTreeData;

#include <QFileInfo>
#include <QList>

#include <QQDir>
#include <QQFileInfo>
#include <QQFileInfoList>
#include <QQString>

class OCIO_EXPORT FileSystemTree
{
public:
    FileSystemTree();
    FileSystemTree(const FileSystemTree &);
    FileSystemTree &operator=(const FileSystemTree &);
    ~FileSystemTree();

public: // access
    QQDir rootDir() const;
    QQDir rootDir(const QQString &pathName);
    QQDir rootDir(const QDir &qdir);
    int fileCount() const;
    int dirCount() const;
    QList<QQFileInfo> fileEntryList() const;
    QList<QQDir> dirEntryList() const;

public: // command
    int add(QFileInfo fi);
    int add(QQDir dir);

private:
    QSharedDataPointer<FileSystemTreeData> data;
};

