#pragma once

#include <QImage>

#include <QQFileInfo>

class BaseImage : public QImage
{
public:
    BaseImage();
    BaseImage(const QImage qimg);

private:
    QQFileInfo mFileInfo;
};

