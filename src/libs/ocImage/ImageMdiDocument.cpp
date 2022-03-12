#include "ImageMdiDocument.h"

ImageMdiDocument::ImageMdiDocument(const QQFileInfo &fileInfo, QObject *parent)
    : MdiDocument{fileInfo, parent}
{
    setObjectName("ImageMdiDocument:"+fileInfo.baseName());
}

bool ImageMdiDocument::load(const QQFileInfo &fi)
{
    mFileInfo = fi;
    return load();
}

bool ImageMdiDocument::load()
{
    Q_ASSERT(false); // MUSTDO it
}

/* ------- generated -------- */

