#include "ImageMdiDocument.h"

#include <MdiGridSubWin>

ImageMdiDocument::ImageMdiDocument(const QQFileInfo &fileInfo, hold-MdiMainWindow *parent)
    : hold-MdiDocument{fileInfo, parent}
{
    setObjectName("ImageMdiDocument:"+fileInfo.baseName());
    mPak.set(fileInfo);
    mpMdiGridSubWin = new MdiGridSubWin(mPak.fileInfo().baseName(), mdiArea());
}

void ImageMdiDocument::load()
{
    hold-MdiDocument::load();
}

void ImageMdiDocument::showOriginalImage(const QQFileInfo &fileInfo)
{
    qDebug() << objectName() << fileInfo;
    QImage tOriginalImage = mPak.original();
    if (tOriginalImage.isNull()) return;                                /* /====\ */

}

/* ------- generated -------- */

