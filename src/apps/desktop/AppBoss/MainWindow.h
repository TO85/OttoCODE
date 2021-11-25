#pragma once

#include <QtCore/QMap>
#include <QtWidgets/QMainWindow>

class ActionManager;
class QQStackedLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ActionManager *actions() { return mpActions; }
    QQStackedLayout *stack() { return mpStack; }

public:

private:
    ActionManager *mpActions=nullptr;
    QQStackedLayout *mpStack=nullptr;
};
