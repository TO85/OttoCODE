#include "EtcSubWinWidget.h"

#include <QtDebug>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

EtcSubWinWidget::EtcSubWinWidget(const QDir &aDir, QQMdiArea *parent, Qt::WindowFlags flags)
    : MdiGridWidget("View/Etc", parent, flags)
    , mDir(aDir)
{
    setObjectName("EtcSubWindow:" + dir().path());
    qDebug() << Q_FUNC_INFO << dir().path() << parent->objectName();
}

const QDir EtcSubWinWidget::dir()
{
    return mDir;
}

void EtcSubWinWidget::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    MdiGridWidget::setup();
    enum Row { DirFileTitleRow=0, DirFileRow, Separator1, FileTitleRow, FileRow };
    enum DirFileColumn { DirView=0, Separator2, FileView };
    enum FileRowColumn { FileColumn = 0, FileColumnSpan = FileView - DirView + 1 };

    QLabel *pDirTitleLabel = new QLabel("Directory: " + dir().path());
    QLabel *pFileTitleLabel = new QLabel("Files:");
    mpFileNameTitleLabel = new QLabel("File: ");

    setWindowTitle(dir().path());
    layout()->addWidget(pDirTitleLabel, DirFileTitleRow, DirView, Qt::AlignLeft);
    layout()->addWidget(pFileTitleLabel, DirFileTitleRow, FileView, Qt::AlignLeft);
    layout()->addWidget(mpFileNameTitleLabel, FileTitleRow, FileColumn, 1, FileColumnSpan, Qt::AlignLeft);
    layout()->setRowMinimumHeight(Separator1, 40);
    layout()->setColumnMinimumWidth(Separator2, 40);
    setLayout(layout());
}
