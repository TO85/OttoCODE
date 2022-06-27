#include "EtcSubWin.h"

#include <QtDebug>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

#include <QQMdiArea>

EtcSubWin::EtcSubWin(QQMdiArea *parent, Qt::WindowFlags flags)
    : QQMdiSubWindow(KeySeg("Etc"), parent, flags)
{
    setObjectName("EtcSubWin");
    qDebug() << Q_FUNC_INFO << parent->objectName();
}

void EtcSubWin::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    enum Row { DirFileTitleRow=0, DirFileRow, Separator1, FileTitleRow, FileRow };
    enum DirFileColumn { DirView=0, Separator2, FileView };
    enum FileRowColumn { FileColumn = 0, FileColumnSpan = FileView - DirView + 1 };
}
