#include "PixmapWidget.h"

#include <QLabel>

PixmapWidget::PixmapWidget(QWidget *parent)
    : QWidget{parent}
{

}

PixmapWidget::PixmapWidget(const QPixmap &pxm, QWidget *parent)
    : QWidget{parent}
    , mPixmap(pxm)
    , mpPixmapLabel(new QLabel(this))
{
    set();
}

void PixmapWidget::set(const QPixmap &pxm)
{
    mPixmap = pxm;
    set();
}

void PixmapWidget::set()
{
    Q_CHECK_PTR(mpPixmapLabel);
    mpPixmapLabel->setPixmap(mPixmap);
}
