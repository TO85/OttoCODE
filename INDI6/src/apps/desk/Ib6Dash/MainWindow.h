#pragma once

#include <QtWidgets/QMainWindow>

#include <eirType/MultiName.h>
class ActionManager;

class MainStack;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    MainStack *stack() { return mpMainStack; }
    ActionManager *actions();
    QAction *action(const MultiName &aName);

public slots:

private slots:
    void initialize();
    void setup();
    void setupActions();
    void setupConnections();
    void setupMenus();

private slots: // actions
    void doConnectServer();

private:
    ActionManager *mpActionManager=nullptr;
    MainStack *mpMainStack=nullptr;
};
