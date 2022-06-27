#include "PixcelsiorMain.h"

#include <QtDebug>
#include <QApplication>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

#include <ActionManager>
#include <ImageFileDialog>
#include <JsonMap>
#include <QQMdiArea>

#include "PixcelsiorImageDocument.h"
#include "PixcelsiorDocumentGrid.h"

ExcelsiorMain::ExcelsiorMain(QWidget *parent, Qt::WindowFlags flags)
    : QQMainWindow(parent, flags)
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
    setupUI();
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
    connect(this, &ExcelsiorMain::openFile,
            this, &ExcelsiorMain::openDocument);
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

void ExcelsiorMain::setupUI()
{
    qDebug() << Q_FUNC_INFO << objectName();
    mpMdiArea = new QQMdiArea(this);
    Q_CHECK_PTR(mpMdiArea);
}

void ExcelsiorMain::setupFileMenu()
{
    qDebug() << Q_FUNC_INFO << objectName();
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

    QQDir tImageDir = mCurrentImageDir;
    if (tImageDir.isNull()) tImageDir = mDefaultImageDir;
    const QQString tPathFileName
            = QFileDialog::getOpenFileName(this, "Open Image File", tImageDir.path());
    if (tPathFileName.isEmpty()) return;                            /* cancel   /====\ */
    const QQFileInfo tImageFI(tPathFileName);
    if (tImageFI.notReadable()) return;                             /* missing  /====\ */
    mCurrentImageDir = tImageFI.dir();
    qDebug() << tImageFI;
    emit openFile(tImageFI);
}

void ExcelsiorMain::openDocument(const QQFileInfo &fileInfo)
{
    PixcelsiorImageDocument * pDoc = new PixcelsiorImageDocument(fileInfo, this);
    if (pDoc->notNull())
        mFileInfoImageDocumentMap.insert(fileInfo, pDoc);
    PixcelsiorDocumentGrid tDocGrid(pDoc);
    PixcelsiorImageGridBlock * pBlock = pDoc->generateBlock();
    tDocGrid.add(pBlock);

}

/* ------------------- private ---------------------- */



