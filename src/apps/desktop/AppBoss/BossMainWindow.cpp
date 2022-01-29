#include "BossMainWindow.h"

#include <QtCore/QDir>
#include <QtCore/QTimer>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

#include <ActionManager>
#include <MdiGridWindow>
#include <MenuManager>

#include "EtcSubWindow.h"

BossMainWindow::BossMainWindow(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("AppBoss:MainWindow");
    setWindowTitle("OttoCODE AppBoss");
    QTimer::singleShot(100, this, &BossMainWindow::setup);
}

BossMainWindow::~BossMainWindow()
{
}

void BossMainWindow::viewEtc()
{
    qDebug(Q_FUNC_INFO);
    EtcSubWindow *pEtcWindow = new EtcSubWindow(QDir("/etc"), mdiArea());
    addSubWindow(pEtcWindow);
    pEtcWindow->setup();
}

void BossMainWindow::setupMenus()
{
    QMenu * pView = menus()->addPrimary("View");
    Q_UNUSED(pView); // TODO need?
    QAction *pViewEtc = menus()->add("View/Etc");
    Q_UNUSED(pViewEtc); // TODO add tool tips, etc.

    QMenu * pWindow = menus()->addPrimary("Window");
    // NEEDDO Placeholder for open windows
    pWindow->addSeparator();
    QAction *pSubWindow = menus()->add("Window/SubWindow", "Sub &Window");
    QAction *pTabbed = menus()->add("Window/Tabbed");
    Q_UNUSED(pSubWindow); // TODO add tool tips, etc.
    Q_UNUSED(pTabbed);

    QMenu * pHelp = menus()->addPrimary("Help");
    pHelp->addSeparator();
    QAction *pAboutQt = menus()->add("Help/AboutQt", "About &Qt");
    QAction *pAboutOttoCode = menus()->add("Help/AboutOttoCode", "About &OttoCODE");
    QAction *pAboutAppBoss = menus()->add("Help/AppBoss", "About App&Boss");
    Q_UNUSED(pAboutQt); // TODO add tool tips, etc.
    Q_UNUSED(pAboutOttoCode);
    Q_UNUSED(pAboutAppBoss);
}

void BossMainWindow::setupConnections()
{
    actions()->connect("Help/AboutQt", gui(), "aboutQt()");
    actions()->connect("Window/SubWindow", this, "windowSubView()");
    actions()->connect("Window/Tabbed", this, "windowTabbed()");
    actions()->connect("View/Etc", this, "viewEtc()");
}
