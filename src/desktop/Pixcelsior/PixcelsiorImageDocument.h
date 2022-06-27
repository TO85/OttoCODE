#pragma once

#include <QObject>

#include <QMap>

#include <KeySeg>
#include <Image>
#include <ImagePak>
#include <Size>
class QQMdiSubWindow;

#include "PixcelsiorImageGridBlock.h"

class PixcelsiorImageDocument : public QObject
{
    Q_OBJECT

public:
    explicit PixcelsiorImageDocument(const QQFileInfo &fi, QObject *parent = nullptr);
    QQMdiSubWindow * subWindow();
    ImagePak & pak() { return mImagePak; }
    ImagePak pak() const { return mImagePak; }
    KeySeg name() const;

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }

public:
    PixcelsiorImageGridBlock *generateBlock(const PixcelsiorImageGridBlock::Type btype
                                           = PixcelsiorImageGridBlock::TallQuadBlock);

signals:

private:
    const QQFileInfo cmFileInfo;
    ImagePak mImagePak;
    QQMdiSubWindow * mpSubWindow=nullptr;
    PixcelsiorDocumentGrid * mpMainImageGrid=nullptr;
};

