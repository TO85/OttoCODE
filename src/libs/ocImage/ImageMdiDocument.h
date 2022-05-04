#pragma once

#include <MdiDocument>

#include <MdiMainWindow>
#include <QQFileInfo>

#include "ImagePak.h"
class MdiGridWidget;

class ImageMdiDocument : public hold-MdiDocument
{
    Q_OBJECT
public:
    explicit ImageMdiDocument(const QQFileInfo &fileInfo, hold-MdiMainWindow *parent=nullptr);
    ImagePak pak() const { return mPak; }
    ImagePak & pak() { return mPak; }

public slots:
    void load();
    void showOriginalImage(const QQFileInfo & fileInfo);

signals:
    void loaded();

private:
    hold-MdiGridSubWin *mpMdiGridSubWin=nullptr;
    ImagePak mPak;
};

