#include "EtcSubWindow.h"

#include <QtDebug>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

EtcSubWindow::EtcSubWindow(const QDir &aDir, QQMdiArea *parent, Qt::WindowFlags flags)
    : MdiGridWindow("View/Etc", parent, flags)
    , mDir(aDir)
{
    setObjectName("EtcSubWindow:" + dir().path());
    qDebug() << Q_FUNC_INFO << dir().path() << parent->objectName();
}

const QDir EtcSubWindow::dir()
{
    return mDir;
}

void EtcSubWindow::setup()
{
    qDebug(Q_FUNC_INFO);
    MdiGridWindow::setup();
    enum Row { DirFileTitleRow=0, DirFileRow, Separator1, FileTitleRow, FileRow };
    enum DirFileColumn { DirView=0, Separator2, FileView };
    enum FileRowColumn { FileColumn = 0, FileColumnSpan = FileView - DirView + 1 };

    QLabel *pDirTitleLabel = new QLabel("Directory: " + dir().path());
    QLabel *pFileTitleLabel = new QLabel("Files:");
    mpFileNameTitleLabel = new QLabel("File: ");

    layout()->addWidget(pDirTitleLabel, DirFileTitleRow, DirView, Qt::AlignLeft);
    layout()->addWidget(pFileTitleLabel, DirFileTitleRow, FileView, Qt::AlignLeft);
    layout()->addWidget(mpFileNameTitleLabel, FileTitleRow, FileColumn, 1, FileColumnSpan, Qt::AlignLeft);
    layout()->setRowMinimumHeight(Separator1, 40);
    layout()->setColumnMinimumWidth(Separator2, 40);
}
