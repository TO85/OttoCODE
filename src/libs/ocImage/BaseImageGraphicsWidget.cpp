#include "BaseImageGraphicsWidget.h"

BaseImageGraphicsWidget::BaseImageGraphicsWidget(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("BaseImageGraphicsWidget");
}

void BaseImageGraphicsWidget::set(const QPixmap pxmp, const Rational scale)
{
    mPixmap = pxmp, mPixmapScale = scale;
    mPixmapRect.size(pxmp.size(), scale);
    update();
}

void BaseImageGraphicsWidget::setBackground(const QBrush backBrush, const QPixmap backImage)
{

}

void BaseImageGraphicsWidget::update()
{

}
