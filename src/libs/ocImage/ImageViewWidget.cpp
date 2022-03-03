#include "ImageViewWidget.h"

ImageViewWidget::ImageViewWidget(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("ImageWidget");
    qDebug() << Q_FUNC_INFO << objectName();
}

ImageViewWidget::ImageViewWidget(const ImageData imageData, QWidget *parent)
    : QWidget{parent}
    , ImageData(imageData)
{


}
