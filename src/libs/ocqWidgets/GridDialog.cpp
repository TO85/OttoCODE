#include "GridDialog.h"

#include <QGridLayout>
#include <QVBoxLayout>

GridDialog::GridDialog(QWidget *parent, Qt::WindowFlags flags)
    : QDialog(parent, flags)
    , mpButtonBox(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this))
{
    ctor();
    setObjectName("GridDialog");
    qDebug() << Q_FUNC_INFO << (parent ? parent->objectName() : "{orphan}") << Qt::hex << flags;
}

GridDialog::GridDialog(QDialogButtonBox::StandardButtons buttons, QWidget *parent, Qt::WindowFlags flags)
    : QDialog(parent, flags)
    , mpButtonBox(new QDialogButtonBox(buttons, this))
{
    ctor();
    setObjectName("GridDialog");
    qDebug() << Q_FUNC_INFO << (parent ? parent->objectName() : "{orphan}") << Qt::hex << buttons << flags;
}

QDialogButtonBox * GridDialog::buttonBox()
{
    return mpButtonBox;
}

void GridDialog::ctor()
{
    mpMainVBox = new QVBoxLayout(this);
    mpGridWidget = new QWidget(this);
    mpGridLayout = new QGridLayout();
    mpGridWidget->setLayout(mpGridLayout);
    mpMainVBox->addWidget(mpButtonBox);
    mpMainVBox->addWidget(mpGridWidget);
    setLayout(mpMainVBox);
}
