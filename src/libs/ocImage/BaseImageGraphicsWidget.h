#pragma once

#include <QWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
class QBrush;

#include <Rect>
#include <Rational>

#include "Image.h"
#include "ColorFloatQImage.h"

class BaseImageGraphicsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseImageGraphicsWidget(QWidget *parent = nullptr);

public slots:
    void clear();
    void set(const Image::Type itype, const QImage image, const Rational scale=Rational(1,1));
    void setBackground(const QBrush backBrush, const QPixmap backImage=QPixmap());
    void update();

signals:
    void pixmapSet(const QPixmap pxmp);

private:
    Image::Type mType=Image::$nullType;
    QGraphicsScene * mpScene=nullptr;
    QGraphicsView * mpView=nullptr;
    QGraphicsPixmapItem * mpGraphicsPixmapItem=nullptr;
    QImage mImage;
    QPixmap mPixmap;
    Rational mPixmapScale;
    Rect mPixmapRect;
    Rect mScaledRect;
    Rational mViewZoom;
    Rect mViewRect;
    Rect mZoomedRect;
    QBrush mBackBrush;
    QPixmap mBackImage;
};

