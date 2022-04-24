#include "ExcelsiorMain.h"

#include <QtDebug>
#include <QApplication>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

#include <ActionManager>
#include <ImageFileDialog>
#include <JsonMap>


ExcelsiorMain::ExcelsiorMain(QWidget *parent, Qt::WindowFlags flags)
    : MdiMainWindow(parent, flags)
{
    setObjectName("Excelsior:MainWindow");
    qDebug() << Q_FUNC_INFO << objectName();
}

/* ------------------- public slots  ---------------------- */

void ExcelsiorMain::start()
{
    qDebug() << Q_FUNC_INFO << objectName();
    setupActions();
    setupConnections();
    setupMenus();
    show();
}

/* ------------------- private slots  ---------------------- */

void ExcelsiorMain::setupActions()
{
    ACTMGR->add("Quit");
    ACTMGR->add("File/OpenImage", "Open I&mage");
}

void ExcelsiorMain::setupConnections()
{
    ACTMGR->connectSlot("Quit", qApp, "quit()", true);
    ACTMGR->connectSlot("File/OpenImage", this, "openFileAction()");
}

void ExcelsiorMain::setupMenus()
{
    qDebug() << Q_FUNC_INFO << objectName();
    setupFileMenu();
    setupEditMenu();
    setupViewMenu();
    setupWindowMenu();
    setupHelpMenu();
    menuBar()->show();
}

void ExcelsiorMain::setupFileMenu()
{
    QMenu * pFileMenu = menuBar()->addMenu("File");
    pFileMenu->addAction(ACTMGR->action("File/OpenImage"));
    pFileMenu->addSeparator();
    pFileMenu->addAction(ACTMGR->action("Quit"));
}

void ExcelsiorMain::setupEditMenu()
{

}

void ExcelsiorMain::setupViewMenu()
{

}

void ExcelsiorMain::setupWindowMenu()
{

}

void ExcelsiorMain::setupHelpMenu()
{

}


void ExcelsiorMain::openFileAction()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName() << mCurrentImageDir << mDefaultImageDir;

    /* ---------- Open File Dialog ----------- */
    QQDir tImageDir = mCurrentImageDir;
    if (tImageDir.isNull()) tImageDir = mDefaultImageDir;
    const QQString tPathFileName
            = QFileDialog::getOpenFileName(this, "Open Image File", tImageDir.path());
    if (tPathFileName.isEmpty()) return;                            /* cancel /====\ */
    const QQFileInfo tImageFI(tPathFileName);
    if (tImageFI.notExists()) return;                              /* missing /====\ */
    mCurrentImageDir = tImageFI.dir();
    qDebug() << tImageFI;

    /* ----------- Open & Display ------------- */
    ExcelsiorFrameGridMdiSub * pMdiSub = addSubWindow(tImageFI);
    if (pMdiSub) mFileInfoSubWinMap.insert(tImageFI, pMdiSub);
}

ExcelsiorFrameGridMdiSub *ExcelsiorMain::addSubWindow(const QQFileInfo &fi)
{
    ExcelsiorFrameGridMdiSub * result=nullptr;

    return result;
}

/* ------------------- private ---------------------- */



