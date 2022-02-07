#pragma once
#include "ocIO.h"

#include <QSharedDataPointer>
class FileSystemTreeData;

#include <QFileInfo>

#include <QQDir>
#include <QQFileInfo>
#include <List>
#include <String>

class OCIO_EXPORT FileSystemTree
{
public:
    FileSystemTree();
    FileSystemTree(const FileSystemTree &);
    FileSystemTree &operator=(const FileSystemTree &);
    ~FileSystemTree();

public: // access
    QQDir rootDir() const;
    QQDir rootDir(const String &pathName);
    QQDir rootDir(const QDir &qdir);
    int fileCount() const;
    int dirCount() const;
    List<QQFileInfo> fileEntryList() const;
    List<QQDir> dirEntryList() const;

public: // command
    int add(QFileInfo fi);
    int add(QQDir dir);

private:
    QSharedDataPointer<FileSystemTreeData> data;
};

