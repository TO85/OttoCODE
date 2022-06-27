#include "PixcelsiorImageDocument.h"

#include <QQMdiSubWindow>

#include "PixcelsiorDocumentGrid.h"

PixcelsiorImageDocument::PixcelsiorImageDocument(const QQFileInfo &fileInfo, QObject *parent)
    : QObject{parent}
    , cmFileInfo(fileInfo)
    , mpSubWindow(new QQMdiSubWindow(name()))
    , mpMainImageGrid(new PixcelsiorDocumentGrid(this))
{
    setObjectName("PixcelsiorImageDocument:" + name());
}

QQMdiSubWindow *PixcelsiorImageDocument::subWindow()
{
    Q_CHECK_PTR(mpSubWindow);
    return mpSubWindow;
}

KeySeg PixcelsiorImageDocument::name() const
{
    return cmFileInfo.baseName();
}

bool PixcelsiorImageDocument::isNull() const
{
    return pak().contains(Image::OriginalQImage);
}

PixcelsiorImageGridBlock * PixcelsiorImageDocument::generateBlock(const PixcelsiorImageGridBlock::Type btype)
{
    PixcelsiorImageGridBlock * result = new PixcelsiorImageGridBlock(mpMainImageGrid);
    Q_ASSERT(!"TODO"); Q_UNUSED(btype);
    return result;
}
