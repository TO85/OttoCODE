#include "ExcelsiorMain.h"

#include <QtDebug>
#include <QApplication>
#include <QFileDialog>
#include <QMenu>
#include <QTimer>

#include <ActionManager>
#include <ImageFileDialog>
#include <ImageMdiDocument>
#include <JsonMap>


ExcelsiorMain::ExcelsiorMain(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("Excelsior:MainWindow");
    qDebug() << Q_FUNC_INFO << objectName();
    QTimer::singleShot(500, this, &ExcelsiorMain::setup);
}

void ExcelsiorMain::setupActions()
{
    actions()->add("Quit");
    actions()->add("File/OpenImage", "Open I&mage");
}

void ExcelsiorMain::setupConnections()
{
    actions()->connectSlot("Quit", qApp, "quit()", true);
    actions()->connectSlot("File/OpenImage", this, "openFileAction()");
}

void ExcelsiorMain::setupMenus()
{
    qDebug() << Q_FUNC_INFO << objectName();

    addMenu("MenuBar10/File");
    addMenu("MenuBar20/Edit");
    addMenu("MenuBar50/View");
    addMenu("MenuBar70/Window");
    addMenu("MenuBar90/Help");

    setupFileMenu();
    setupEditMenu();
    setupViewMenu();
    setupWindowMenu();
    setupHelpMenu();
}

void ExcelsiorMain::setupFileMenu()
{
    QMenu * pFileMenu = menu("MenuBar10/File");
    pFileMenu->addAction(action("File/OpenImage"));
    pFileMenu->addSeparator();
    pFileMenu->addAction(action("Quit"));
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
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName() << mCurrentImageDir << mDefaultImageDir;

    QQDir tImageDir = mCurrentImageDir;
    if (tImageDir.isNull()) tImageDir = mDefaultImageDir;
    const QQString tPathFileName
            = QFileDialog::getOpenFileName(this, "Open Image File", tImageDir.path());
    const QQFileInfo tImageFI(tPathFileName);
    qDebug() << tImageFI;
    ImageMdiDocument *pImageDoc = new ImageMdiDocument(tImageFI, this);
    Q_ASSERT(pImageDoc);
    add(tImageFI, pImageDoc);

    pImageDoc->load();


}
