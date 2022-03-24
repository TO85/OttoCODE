#include "FrameImageDocument.h"

FrameImageDocument::FrameImageDocument(const QQFileInfo &fileInfo,
                                       MdiMainWindow *parent)
    : ImageMdiDocument{fileInfo, parent}
    , mpImageWidget(new FrameGraphicsWidget())
{
    setObjectName("FrameImageDocument");
}
