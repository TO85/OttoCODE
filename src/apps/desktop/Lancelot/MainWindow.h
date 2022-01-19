#pragma once

#include <QQMainWindow>

#include <QPointer>
class QApplication;
class QMdiArea;
class QMenuBar;

class ActionManager;

class MainWindow : public QQMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication *app);
    ~MainWindow();

public:
    QMdiArea *mdi();

public:
    void setup();

private slots:
    void setupStart();
    void setupMenus();
    void setupActions();
    void setupConnections();
    void setupWidgets();
    void setupFinish();

    void windowTabbed();
    void windowSubView();

private:

signals:
    void setupComplete();

private slots:

private:
    QMdiArea *mpMdiArea;
};
