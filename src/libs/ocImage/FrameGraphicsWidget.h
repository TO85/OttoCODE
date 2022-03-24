#pragma once
#include "ocImage.h"

#include "BaseImageGraphicsWidget.h"
#include "ColorQImage.h"
#include "ColorFloatQImage.h"

class OCIMAGE_EXPORT FrameGraphicsWidget : public BaseImageGraphicsWidget
{
    Q_OBJECT
public:
    FrameGraphicsWidget(QWidget *parent = nullptr);

public slots:
    void load(const ColorQImage cqi);
    void load(const ColorFloatQImage cfqi);


signals:
    void loaded(const ColorQImage cqi);
    void loaded(const ColorFloatQImage cfqi);


};

