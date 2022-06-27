#include "PixcelsiorImageGridBlock.h"

#include "PixcelsiorImageDocument.h"
#include "PixcelsiorDocumentGrid.h"
#include "PixcelsiorImageGridBlock.h"

PixcelsiorImageGridBlock::PixcelsiorImageGridBlock(PixcelsiorDocumentGrid *pMainGrid)
    : mpMainGrid(pMainGrid)
{
    setObjectName("PixcelsiorImageGridBlock:" + grid()->doc()->name());
}

PixcelsiorDocumentGrid *PixcelsiorImageGridBlock::grid()
{
    Q_ASSERT(mpMainGrid);
    return mpMainGrid;
}
