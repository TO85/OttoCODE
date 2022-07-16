#include "MainWindow.h"

#include <QMenuBar>

#include "FileTaskMenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpFileMenu(new FileTaskMenu(tr("&File"), this))
{
    setObjectName("MainWindow:lirview");
    setWindowTitle("lirview by OttoCODE");
}

MainWindow::~MainWindow() {;}

void MainWindow::setup()
{
    mpFileMenu->setup();
    menuBar()->addMenu(mpFileMenu);

    menuBar()->show();
    show();
}


