#pragma once

#include <ImageMdiDocument>
#include <FrameGraphicsWidget>

class FrameImageDocument : public ImageMdiDocument
{
    Q_OBJECT
public:
    explicit FrameImageDocument(const QQFileInfo &fileInfo, MdiMainWindow *parent = nullptr);


public:
    FrameGraphicsWidget * mpImageWidget=nullptr;
};

