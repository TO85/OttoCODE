#include "BaseImageGraphicsWidget.h"

#include <QGridLayout>
#include <QLabel>

BaseImageGraphicsWidget::BaseImageGraphicsWidget(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("BaseImageGraphicsWidget");
}

void BaseImageGraphicsWidget::clear()
{
    mType = Image::$nullType;
    mpView->deleteLater();
    mpScene->deleteLater();
    mpScene = nullptr;
    mpView = nullptr;
    mpGraphicsPixmapItem = nullptr;
    mImage = QImage();
    mPixmap = QPixmap();
    mPixmapRect = Rect();
    mScaledRect = Rect();
    mViewRect = Rect();
    mZoomedRect = Rect();
    mPixmapScale.set(1, 1);
}

void BaseImageGraphicsWidget::set(const Image::Type itype, const QImage image, const Rational scale)
{
    mType = itype, mImage = image, mPixmapScale = scale;
    mPixmapRect = image.rect();
    mScaledRect = mPixmapRect.scaled(scale);
    const QImage tScaledImage = image.scaled(mScaledRect.size().toQSize());
    mPixmap = QPixmap::fromImage(tScaledImage);
    mpScene = new QGraphicsScene(mScaledRect.toQRect(), this);
    mpView = new QGraphicsView(mpScene, this);
    mViewRect = mZoomedRect = mScaledRect;
    mpGraphicsPixmapItem = mpScene->addPixmap(mPixmap);
    emit pixmapSet(mPixmap);
    update();
}

void BaseImageGraphicsWidget::setBackground(const QBrush backBrush, const QPixmap backImage)
{

}

void BaseImageGraphicsWidget::update()
{
    QWidget::update(mPixmapRect);
}
