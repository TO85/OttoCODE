#pragma once

#include <QObject>

#include <QDirIterator>

#include <QQString>

#include "FileSystemTree.h"
class DirectoryInfo;
class DirectoryTreeEntry;
class FileTreeEntry;

class FileSystemObject : public QObject
{
    Q_OBJECT
public:
    explicit FileSystemObject(QObject *parent = nullptr);
    explicit FileSystemObject(const QQString &rootPath, QObject *parent = nullptr);


public slots:
    void setRoot(const QQString &rootPath);
    void start();
    void next();
    void finish();

signals:
    void rootSet(const DirectoryInfo &dirInfo);
    void started();
    void fileEntry(const FileTreeEntry &fte);
    void dirEntry(const DirectoryTreeEntry &gte);

private:
    FileSystemTree mTree;
    QDirIterator const * cmpIterator=nullptr;
};

