#pragma once


#include <Image>
#include <Point>
#include <Size>

class PixcelsiorImageGridBlock;

class PixcelsiorImageGridItem
{
public:
    PixcelsiorImageGridItem(PixcelsiorImageGridBlock * pBlock);
    PixcelsiorImageGridItem(PixcelsiorImageGridBlock * pBlock, const Image::Type itype,
                            const Point anchor, const Size span=Size(1,1));

public:
    bool set(const Image::Type itype, const Point anchor, const Size span=Size(1,1));

private:
    PixcelsiorImageGridBlock * mpBlock=nullptr;
    Image::Type mType=Image::$nullType;
    Point mAnchor;
    Size mSpan;
};

