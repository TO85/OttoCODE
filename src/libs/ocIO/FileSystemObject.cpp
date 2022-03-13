#include "FileSystemObject.h"

#include <QtDebug>
#include <QTimer>

FileSystemObject::FileSystemObject(QObject *parent) : QObject{parent} {;}

FileSystemObject::FileSystemObject(const QString &rootPath, QObject *parent)
    : QObject{parent}
{
    RootDir(rootPath);
}

void FileSystemObject::start()
{
    qDebug(Q_FUNC_INFO);
    mpIterator = new QDirIterator(mTree.rootDir(), QDirIterator::Subdirectories);
    if (mpIterator->hasNext())
        QTimer::singleShot(mSampleMsec, this, &FileSystemObject::next);
    else
        QTimer::singleShot(mSampleMsec, this, &FileSystemObject::finish);
    emit started();
}

void FileSystemObject::next()
{
    qDebug(Q_FUNC_INFO);
    if (mpIterator->hasNext())
    {
        mpIterator->next();
        QFileInfo tFI = mpIterator->fileInfo();
        if (tFI.isDir())
        {
            mTree.add(tFI);
            emit fileInfo(tFI);
        }
        else
        {
            mTree.add(tFI.dir());
            emit dirEntry(tFI.dir());
        }
        QTimer::singleShot(mSampleMsec, this, &FileSystemObject::next);
    }
    else
    {
        QTimer::singleShot(mSampleMsec, this, &FileSystemObject::finish);
    }
}

void FileSystemObject::finish()
{
    qDebug(Q_FUNC_INFO);
    // TODO anything?
    emit finished(tree().fileCount(), tree().dirCount());
}

/* -------------------------- generated -------------------------- */

int FileSystemObject::SampleMsec() const
{
    return mSampleMsec;
}

void FileSystemObject::SampleMsec(int newSampleMsec)
{
    if (mSampleMsec == newSampleMsec)
        return;
    mSampleMsec = newSampleMsec;
    emit SampleMsecChanged(mSampleMsec);
}

void FileSystemObject::resetSampleMsec()
{
    SampleMsec(10);
}

const QQDir &FileSystemObject::RootDir() const
{
    return mRootDir;
}

void FileSystemObject::RootDir(const QQDir &newRootDir)
{
    if (mRootDir == newRootDir)
        return;
    mRootDir = newRootDir;
    emit RootDirChanged(mRootDir);
}

void FileSystemObject::resetRootDir()
{
    RootDir(QQDir::nullDir());
}
