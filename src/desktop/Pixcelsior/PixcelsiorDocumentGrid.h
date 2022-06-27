#pragma once

#include <QQGridLayout>

#include <QList>

#include <Image>
#include <Point>
#include <Size>

#include "PixcelsiorImageGridBlock.h"
class PixcelsiorImageDocument;

class PixcelsiorDocumentGrid : public QQGridLayout
{
public:
    PixcelsiorDocumentGrid(PixcelsiorImageDocument * pDocument);
    PixcelsiorImageDocument * doc() const;

public:
    void add(PixcelsiorImageGridBlock *block);

private:
    PixcelsiorImageDocument * mpDocument;
    int mPrimaryRectRound = 16;
    int mPrimaryScale=12;
    int mPrimaryMaxDim=768;
    Size mPrimarySize;
    QList<PixcelsiorImageGridBlock *> mBlocks;
};

