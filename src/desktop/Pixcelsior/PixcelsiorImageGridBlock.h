#pragma once

#include <QQGridLayout>

#include <QList>

#include "PixcelsiorImageGridItem.h"
class PixcelsiorDocumentGrid;

class PixcelsiorImageGridBlock : public QQGridLayout
{
public:
    enum Type
    {
        $nullType,
        ShortQuadBlock,
        TallQuadBlock,
        QuadSpace,
        TriSpace,
        $sizeType
    };

public:
    PixcelsiorImageGridBlock(PixcelsiorDocumentGrid * pMainGrid);
    PixcelsiorDocumentGrid * grid();

public:
    bool generate(const Type btype);
    bool generate(const Type btype, const Image::Type itype);
    bool generate(const Type btype, const Image::TypeList & itypes);

private:
    PixcelsiorDocumentGrid * mpMainGrid=nullptr;
    QList<PixcelsiorImageGridItem> mItems;
};

