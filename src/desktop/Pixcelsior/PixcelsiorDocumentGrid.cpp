#include "PixcelsiorDocumentGrid.h"

#include <CRect>

#include "PixcelsiorImageDocument.h"


PixcelsiorDocumentGrid::PixcelsiorDocumentGrid(PixcelsiorImageDocument *pDocument)
    : mpDocument(pDocument)
{
    setObjectName("PixcelsiorImageGrid" + doc()->name());
    const QImage tOriginalImage = doc()->pak().original();
    CRect tPrimaryRect = tOriginalImage.rect();
    tPrimaryRect.round(mPrimaryRectRound);
    const QImage tPrimaryImage = tOriginalImage.copy(tPrimaryRect);
    doc()->pak().set(Image::PrimaryImage, tPrimaryImage);
}

PixcelsiorImageDocument *PixcelsiorDocumentGrid::doc() const
{
    Q_ASSERT(mpDocument);
    return mpDocument;
}

void PixcelsiorDocumentGrid::add(PixcelsiorImageGridBlock *block)
{
    mBlocks.append(block);
}
