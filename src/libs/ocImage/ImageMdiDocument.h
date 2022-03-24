#pragma once

#include <MdiDocument>

#include <MdiMainWindow>
#include <QQFileInfo>

#include "ImagePak.h"

class ImageMdiDocument : public MdiDocument
{
    Q_OBJECT
public:
    explicit ImageMdiDocument(const QQFileInfo &fileInfo, MdiMainWindow *parent=nullptr);
    ImagePak pak() const { return mPak; }
    ImagePak & pak() { return mPak; }

public:
    virtual void load() override;

private:
    ImagePak mPak;
};

