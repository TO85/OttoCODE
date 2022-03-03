#include "ImageFileDialog.h"

ImageFileDialog::ImageFileDialog(const Mode mode, QWidget *parent, Qt::WindowFlags flags)
    : GridDialog(parent, flags)
    , mMode(mode)
{
    setObjectName("ImageFileDialog");
    qDebug() << Q_FUNC_INFO << mMode << (parent ? parent->objectName() : "{orphan}") << Qt::hex << flags;

}

ImageFileDialog::ImageFileDialog(const Mode mode, QDialogButtonBox::StandardButtons buttons, QWidget * parent, Qt::WindowFlags flags)
    : GridDialog(buttons, parent, flags)
    , mMode(mode)
{
    setObjectName("ImageFileDialog");
    qDebug() << Q_FUNC_INFO << mMode << (parent ? parent->objectName() : "{orphan}") << Qt::hex << buttons << flags;
}

ImageFileDialog::Mode ImageFileDialog::mode() const
{
    return mMode;
}

void ImageFileDialog::mode(const ImageFileDialog::Mode newMode)
{
    mMode = newMode;
    emit modeChanged(newMode);
}
