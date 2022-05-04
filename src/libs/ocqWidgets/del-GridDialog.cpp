#include "hold-GridDialog.h"

#include <QGridLayout>
#include <QVBoxLayout>

GridDialog::hold-GridDialog(QWidget *parent, Qt::WindowFlags flags)
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
    Q_CHECK_PTR(this);
    Q_ASSERT(mpButtonBox);
    return mpButtonBox;
}

QGridLayout *GridDialog::grid()
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpGridLayout);
    return mpGridLayout;
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
    mpGridWidget->show();
    Q_ASSERT(connect(mpButtonBox, &QDialogButtonBox::accepted,
                     this, &QDialog::accept));
    Q_ASSERT(connect(mpButtonBox, &QDialogButtonBox::rejected,
                     this, &QDialog::reject));
}

