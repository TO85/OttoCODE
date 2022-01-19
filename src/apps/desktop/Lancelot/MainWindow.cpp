#include "MainWindow.h"

#include <QtDebug>
#include <QApplication>
#include <QMdiArea>
#include <QTimer>

#include <ActionManager>

//#include "../../../include/ActionManager"

MainWindow::MainWindow(QApplication *app)
    : QQMainWindow(app)
{
    qDebug(Q_FUNC_INFO);
}

MainWindow::~MainWindow()
{
}

QMdiArea *MainWindow::mdi()
{
    Q_ASSERT(mpMdiArea);
    return mpMdiArea;
}

void MainWindow::setup()
{
    qDebug(Q_FUNC_INFO);
    mpMdiArea = new QMdiArea(this);

    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupStart);
}

void MainWindow::setupStart()
{
    qDebug(Q_FUNC_INFO);

    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupMenus);
}

void MainWindow::setupMenus()
{
    qDebug(Q_FUNC_INFO);

    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupActions);
}

void MainWindow::setupActions()
{
    qDebug(Q_FUNC_INFO);
    actions()->add("Window/Tabbed");
    actions()->add("Window/SubView");
    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupConnections);
}

void MainWindow::setupConnections()
{
    qDebug(Q_FUNC_INFO);

    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupWidgets);
}

void MainWindow::setupWidgets()
{
    qDebug(Q_FUNC_INFO);

    // TODO
    QTimer::singleShot(100, this, &MainWindow::setupFinish);
}

void MainWindow::setupFinish()
{
    qDebug(Q_FUNC_INFO);

    // TODO
    emit setupComplete();
}

void MainWindow::windowTabbed()
{
    mdi()->setViewMode(QMdiArea::TabbedView);
}

void MainWindow::windowSubView()
{
    mdi()->setViewMode(QMdiArea::SubWindowView);
}

