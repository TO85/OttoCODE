#pragma once

#include <QWidget>

#include "ImageData.h"

class ImageViewWidget : public QWidget, public ImageData
{
    Q_OBJECT
public:
    explicit ImageViewWidget(QWidget *parent = nullptr);
    ImageViewWidget(const ImageData imageData, QWidget *parent = nullptr);

signals:

};

