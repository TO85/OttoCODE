#include "ImageFileDialog.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

ImageFileDialog::ImageFileDialog(const Mode mode, QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
    , mMode(mode)
{
    Q_CHECK_PTR(this);
    setObjectName("ImageFileDialog");
    qDebug() << Q_FUNC_INFO << mMode << (parent ? parent->objectName() : "{orphan}") << Qt::hex << flags;
    setup();
}

void ImageFileDialog::setup()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mMode;
    mpDirectoryText = new QTextEdit("current directory");
    setupActions();
    setupConnections();
    setupDirectory();
}

void ImageFileDialog::setupActions()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mMode;
    mpBrowseDirectoryAct = new QAction(this);
    mpDefaultDirectoryAct = new QAction(this);
}

void ImageFileDialog::setupConnections()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mMode;
    Q_ASSERT(connect(this, &ImageFileDialog::directoryChanged,
                     this, &ImageFileDialog::doDirectoryChanged));
    Q_ASSERT(connect(this, &ImageFileDialog::defaultDirectoryChanged,
                     this, &ImageFileDialog::doDefaultDirectoryChanged));


}

void ImageFileDialog::setupDirectory()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mMode;
    Q_ASSERT(mpDirectoryText);
    mpDirectoryText = new QTextEdit("current directory directory directory directory directory directory");
    mpDirectoryText->setMaximumHeight(24);
    mpDirectoryText->setMinimumWidth(480);
    const int row = DirectoryRow;
    QLabel * pRowLabel = new QLabel("Directory:");
    QPushButton * pBrowseButton = new QPushButton(tr("Browse", "ButtonText"));
    QPushButton * pDefaultButton = new QPushButton(tr("Default", "ButtonText"));
    Q_ASSERT(pRowLabel);
    Q_ASSERT(pBrowseButton);
    Q_ASSERT(pDefaultButton);
    Q_ASSERT(mpBrowseDirectoryAct);
    Q_ASSERT(mpDefaultDirectoryAct);
    Q_ASSERT(pRowLabel);

    mpDirectoryText->setReadOnly(true);
    pBrowseButton->addAction(mpBrowseDirectoryAct);
    pDefaultButton->addAction(mpDefaultDirectoryAct);
/*
    grid()->addWidget(pRowLabel, row, LabelCol);
    grid()->addWidget(mpDirectoryText, row, DisplayCol);
    grid()->addWidget(pDefaultButton, row, Button1Col);
    grid()->addWidget(pBrowseButton, row, BrowseCol);
*/
}

void ImageFileDialog::browseDirectory()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mMode;
    Q_ASSERT(false); // MUSTDO it
}

void ImageFileDialog::doDirectoryChanged(const QQDir &newDirectory)
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << newDirectory;
    mDirectory = newDirectory;
    mpDirectoryText->setText(mDirectory.path());
    doDefaultDirectoryChanged(QQDir());
}

void ImageFileDialog::doDefaultDirectoryChanged(const QQDir &newDefaultDirectory)
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << newDefaultDirectory;
    if (newDefaultDirectory.notNull())
        mDefaultDirectory = newDefaultDirectory;
    if (mDefaultDirectory.isNull())
    {
        mpDefaultDirectoryAct->setDisabled(true);
        qDebug() << "mDefaultDirectory.isNull()" << "mpDefaultDirectoryAct->setDisabled(true)";
    }
    else if (mDirectory == mDefaultDirectory)
    {
        mpDefaultDirectoryAct->setChecked(true);
        mpDefaultDirectoryAct->setCheckable(false);
        qDebug() << "mDirectory == mDefaultDirectory" << "setChecked(true) setCheckable(false)";
    }
    else
    {
        mpDefaultDirectoryAct->setDisabled(false);
        mpDefaultDirectoryAct->setChecked(false);
        mpDefaultDirectoryAct->setCheckable(true);
        qDebug() << "else" << "setDisabled(false) setChecked(false) setCheckable(true)";
    }

}

/* ------- generated -------- */

void ImageFileDialog::defaultDirectory(const QQDir &newDefaultDirectory)
{
    Q_CHECK_PTR(this);
    if (mDefaultDirectory == newDefaultDirectory)
        return;
    mDefaultDirectory = newDefaultDirectory;
    emit defaultDirectoryChanged(mDefaultDirectory);
}

const QQDir &ImageFileDialog::directory() const
{
    Q_CHECK_PTR(this);
    return mDirectory;
}

const QQDir &ImageFileDialog::defaultDirectory() const
{
    Q_CHECK_PTR(this);
    return mDefaultDirectory;
}

void ImageFileDialog::directory(const QQDir &newDirectory)
{
    Q_CHECK_PTR(this);
    if (mDirectory == newDirectory)
        return;
    mDirectory = newDirectory;
    emit directoryChanged(mDirectory);
}

ImageFileDialog::Mode ImageFileDialog::mode() const
{
    Q_CHECK_PTR(this);
    return mMode;
}

void ImageFileDialog::mode(const ImageFileDialog::Mode newMode)
{
    Q_CHECK_PTR(this);
    mMode = newMode;
    emit modeChanged(newMode);
}
