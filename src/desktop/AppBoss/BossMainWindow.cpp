#include "BossMainWindow.h"

#include <QtCore/QDir>
#include <QtCore/QTimer>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

#include <ActionManager>
#include <MdiGridWidget>
#include <MenuManager>

#include "EtcSubWinWidget.h"

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
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    EtcSubWinWidget *pEtcWidget = new EtcSubWinWidget(QDir("/etc"), mdiArea());
    pEtcWidget->setup();
    mdiArea()->addSubWindow(pEtcWidget);
}

void BossMainWindow::aboutOttoCODE()
{
    QMessageBox::about(mdiArea(), "About OttoCODE", "<i>Otto</i><b>CODE</b>"
                       " Copyright (c) 1993-2022, Anthony Otto DBA OttoCODE."
                       " All rights reserved worldwide.");
}

void BossMainWindow::aboutAppBoss()
{
    QMessageBox::about(mdiArea(), "About AppBoss",
                       "<b>AppBoss</b> <i>*nix Menu & Icon Manager</i>"
                       " by <i>Otto</i><b>CODE</b>"
                       " Copyright (c) 1993-2022, Anthony Otto DBA OttoCODE.\n"
                       " All rights reserved worldwide.");
}

void BossMainWindow::setupMenus()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();

    QMenu * pView = menus()->addPrimary("View");
    QAction *pViewEtc = menus()->add("View/Etc");
    Q_UNUSED(pViewEtc); // TODO add tool tips, etc.
    pView->addSeparator();
    QAction * pExit = menus()->add("View/Exit", "E&xit");
    actions()->add("View/Etc", pViewEtc);
    actions()->add("View/Exit", pExit);

    QMenu * pWindow = menus()->addPrimary("Window");
    // NEEDDO Placeholder for open windows
    pWindow->addSeparator();
    QAction *pSubWindow = menus()->add("Window/SubWindow", "Sub &Window");
    QAction *pTabbed = menus()->add("Window/Tabbed");
    // TODO add tool tips, etc.
    actions()->add("Window/SubWindow", pSubWindow);
    actions()->add("Window/Tabbed", pTabbed);

    QMenu * pHelp = menus()->addPrimary("Help");
    pHelp->addSeparator();
    QAction *pAboutQt = menus()->add("Help/AboutQt", "About &Qt");
    QAction *pAboutOttoCode = menus()->add("Help/AboutOttoCode", "About &OttoCODE");
    QAction *pAboutAppBoss = menus()->add("Help/AppBoss", "About App&Boss");
    actions()->add("Help/AboutQt", pAboutQt);
    actions()->add("Help/AboutOttoCode", pAboutOttoCode);
    actions()->add("Help/AppBoss", pAboutAppBoss);
}

void BossMainWindow::setupConnections()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();

    actions()->connectSlot("View/Etc", this, "viewEtc()");
    actions()->connectSlot("Help/AboutQt", qApp, "aboutQt()");
    actions()->connectSlot("Help/AboutOttoCode", this, "aboutOttoCODE()");
    actions()->connectSlot("Help/AppBoss", this, "aboutAppBoss()");
    actions()->connectSlot("Window/SubWindow", this, "windowSubView()", true);
    actions()->connectSlot("Window/Tabbed", this, "windowTabbed()", true);
//    actions()->connectSlot("View/Exit", core(), "quit()");
    Q_ASSERT(connect(actions()->action("View/Exit"), SIGNAL(triggered()), qApp, SLOT(quit())));
}
