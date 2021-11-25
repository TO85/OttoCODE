#include "MainWindow.h"

#include <QtCore/QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

#include <eirExe/ActionManager.h>
#include <eirXfr/Debug.h>

#include "MainStack.h"

MainWindow::MainWindow()
{
    setObjectName("Ib6Dash:MainWindow");
    TRACEQFI << QOBJNAME(parent()) << QOBJNAME(this);
    QTimer::singleShot(50, this, &MainWindow::initialize);
}

MainWindow::~MainWindow()
{
    TRACEQFI << QOBJNAME(this);
    mpMainStack->deleteLater();
    mpActionManager->deleteLater();
}

ActionManager *MainWindow::actions()
{
    AEXPECTPTR(mpActionManager);
    return mpActionManager;
}

QAction *MainWindow::action(const MultiName &aName)
{
    return actions()->action(aName);
}

void MainWindow::initialize()
{
    TRACEQFI << QOBJNAME(this);
    mpActionManager = new ActionManager(this);
    mpMainStack = new MainStack;
    AEXPECTPTR(mpActionManager);
    AEXPECTPTR(mpMainStack);
    TRACEQFI << QOBJNAME(mpActionManager) << QOBJNAME(mpMainStack);
    mpMainStack->initialize();
    QTimer::singleShot(100, this, &MainWindow::setup);
}

void MainWindow::setup()
{
    TRACEQFI << QOBJNAME(this);
    setupActions();
    setupConnections();
    setupMenus();
    mpMainStack->setup();
    setLayout(mpMainStack);
    setCentralWidget(mpMainStack->widget());
    setWindowState(Qt::WindowMaximized);
    mpMainStack->select("Splash");
    update();
}

void MainWindow::setupActions()
{
    TRACEQFI << QOBJNAME(this);
    actions()->add("Quit");
    connect(action("Quit"), &QAction::triggered, qApp, &QApplication::quit);
    actions()->add("Connect/Server");
    connect(action("Connect/Server"), &QAction::triggered,
            this, &MainWindow::doConnectServer);
}

void MainWindow::setupConnections()
{
    TRACEQFI << QOBJNAME(this);
}

void MainWindow::setupMenus()
{
    TRACEQFI << QOBJNAME(this);
    QStatusBar *pStatusBar = statusBar();
    QMenuBar *pMenuBar = menuBar();
    pStatusBar->showMessage("Setting Up");

    QMenu *pConnectMenu = pMenuBar->addMenu("Connect");
    pConnectMenu->addAction(action("Connect/Server"));
    pConnectMenu->addSeparator();
    pConnectMenu->addAction(action("Quit"));
}

void MainWindow::doConnectServer()
{
    stack()->select("Server");
}

