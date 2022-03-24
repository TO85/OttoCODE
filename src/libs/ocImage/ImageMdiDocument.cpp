#include "ImageMdiDocument.h"

ImageMdiDocument::ImageMdiDocument(const QQFileInfo &fileInfo, MdiMainWindow *parent)
    : MdiDocument{fileInfo, parent}
{
    setObjectName("ImageMdiDocument:"+fileInfo.baseName());
}

void ImageMdiDocument::load()
{
    MdiDocument::load(); // read file contents
    if (mBytes.isEmpty())
    {
        mPak.load(fileInfo());
    }
    else
    {
        mPak.set(fileInfo());
        mPak.load(bytes());
    }

}

/* ------- generated -------- */

