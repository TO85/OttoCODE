#include "MainWindow.h"

#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

#include "Actions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpMdiArea(new QMdiArea(this))
    , mpActions(new BaseActions(this))
{
    Q_CHECK_PTR(mpMdiArea);
    setObjectName("Merlin:MainWindow");
    mpMdiArea->setObjectName("Merlin:MdiArea");
    QTimer::singleShot(500, this, &MainWindow::setup);
}

QMdiArea *MainWindow::mdi()
{
    Q_CHECK_PTR(mpMdiArea);
    return mpMdiArea;
}

BaseActions *MainWindow::actions()
{
    Q_CHECK_PTR(mpActions);
    return mpActions;
}

void MainWindow::setup()
{
    qDebug() << Q_FUNC_INFO;
    setupMenuBar();
    setupConnections();
    show();
}

void MainWindow::setupMenuBar()
{
    qDebug() << Q_FUNC_INFO;

    QMenu * pOpenMenu = menuBar()->addMenu("&Open");
    actions()->add("Open/FrameFile", pOpenMenu->addAction("&Frame File"));
    actions()->add("Open/FrameDir", pOpenMenu->addAction("Frame &Dir"));
    actions()->add("Open/SequenceFile", pOpenMenu->addAction("&Sequence File"));
    pOpenMenu->addSeparator();
    actions()->add("Quit", pOpenMenu->addAction("&Quit"));
}

void MainWindow::setupConnections()
{
    qDebug() << Q_FUNC_INFO;
    connect(actions()->action("Open/FrameFile"), &QAction::triggered, actions(), &BaseActions::openFrameFile);
    connect(actions()->action("Open/FrameDir"), &QAction::triggered, actions(), &BaseActions::openFrameDir);
    connect(actions()->action("Open/SequenceFile"), &QAction::triggered, actions(), &BaseActions::openSequenceFile);

}

