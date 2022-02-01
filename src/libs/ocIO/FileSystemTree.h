#pragma once

class FileSystemTreeData;

#include <QDir>
#include <QSharedDataPointer>

#include <QQString>

#include "DirectoryTreeEntry.h"
#include "FileTreeEntry.h"
class DirectoryInfo;

class FileSystemTree
{
public:
    FileSystemTree();
    FileSystemTree(const FileSystemTree &);
    FileSystemTree &operator=(const FileSystemTree &);
    ~FileSystemTree();

public: // access
    DirectoryInfo rootPath() const;
    DirectoryInfo rootPath(const DirectoryInfo &rootDir);
    DirectoryInfo rootPath(const QQString &pathName);
    DirectoryInfo rootPath(const QDir &qdir);
    List<FileTreeEntry> fileEntryList() const;
    List<DirectoryTreeEntry> dirEntryList() const;

public: // command
    int add(FileTreeEntry);
    int add(DirectoryTreeEntry);

private:
    QSharedDataPointer<FileSystemTreeData> data;
};

