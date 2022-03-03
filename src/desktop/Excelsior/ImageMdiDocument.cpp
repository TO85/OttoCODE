#include "ImageMdiDocument.h"

ImageMdiDocument::ImageMdiDocument(QObject *parent)
    : QObject{parent}
{
    setObjectName("ImageMdiDocument");

}

ImageMdiDocument::ImageMdiDocument(const QQFileInfo &fileInfo, QObject *parent)
    : QObject{parent}
    , mFileInfo{fileInfo}
{
    name(fileInfo.baseName());
    setObjectName("ImageMdiDocument:"+name());
}

bool ImageMdiDocument::load(const QQFileInfo &fi)
{
    fileInfo(fi);
    return load();
}

bool ImageMdiDocument::load()
{
    Q_ASSERT(false); // MUSTDO it
}

/* ------- generated -------- */

QString ImageMdiDocument::name() const
{
    return mName;
}

void ImageMdiDocument::name(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged(mName);
}

const QQFileInfo &ImageMdiDocument::fileInfo() const
{
    return mFileInfo;
}

void ImageMdiDocument::fileInfo(const QQFileInfo &newFileInfo)
{
    if (mFileInfo == newFileInfo)
        return;
    mFileInfo = newFileInfo;
    emit fileInfoChanged(mFileInfo);
}
