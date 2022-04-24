#include "ImageMdiDocument.h"

#include <MdiGridWidget>

ImageMdiDocument::ImageMdiDocument(const QQFileInfo &fileInfo, MdiMainWindow *parent)
    : MdiDocument{fileInfo, parent}
{
    setObjectName("ImageMdiDocument:"+fileInfo.baseName());
    mPak.set(fileInfo);
    mpGridWidget = new MdiGridWidget(mPak.fileInfo().baseName(), mdiArea());
}

void ImageMdiDocument::load()
{
    MdiDocument::load();
}

void ImageMdiDocument::showOriginalImage(const QQFileInfo &fileInfo)
{
    qDebug() << objectName() << fileInfo;
    QImage tOriginalImage = mPak.original();
    if (tOriginalImage.isNull()) return;                                /* /====\ */

}

/* ------- generated -------- */

