#pragma once
#include "ocIO.h"

#include <QObject>

#include <QDirIterator>
#include <QFileInfo>

#include <QQDir>

#include "FileSystemTree.h"

class OCIO_EXPORT FileSystemObject : public QObject
{
    Q_OBJECT
public:
    explicit FileSystemObject(QObject *parent = nullptr);
    FileSystemObject(const QString &rootPath, QObject *parent = nullptr);
    ~FileSystemObject() {;}
    FileSystemTree tree() const { return mTree; }
    FileSystemTree & tree() { return mTree; }

public slots:
    void start();


private slots:
    void next();
    void finish();

signals:
    void started();
    void fileInfo(const QFileInfo &fi);
    void dirEntry(const QQDir &dir);
    void finished(const int & fileCount, const int & dirCount);


private:
    FileSystemTree mTree;
    QDirIterator * mpIterator=nullptr;

public: /* ------------------------ generated ------------------------- */
    int SampleMsec() const;

    const QQDir &RootDir() const;

public slots:
    void SampleMsec(int newSampleMsec);
    void resetSampleMsec();

    void RootDir(const QQDir &newRootDir);
    void resetRootDir();

signals:
    void SampleMsecChanged(int SampleMsec);

    void RootDirChanged(const QQDir &RootDir);

private:
    int mSampleMsec=10;
    QQDir mRootDir;
    Q_PROPERTY(int SampleMsec READ SampleMsec WRITE SampleMsec RESET resetSampleMsec NOTIFY SampleMsecChanged)
    Q_PROPERTY(QQDir RootDir READ RootDir WRITE RootDir RESET resetRootDir NOTIFY RootDirChanged)
};

