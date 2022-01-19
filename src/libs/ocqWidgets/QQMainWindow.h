#pragma once

#include <QMainWindow>

class QApplication;

class ActionManager;

class QQMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QQMainWindow(QApplication *app);
    QApplication *gui() const { return mpApplication; }
    ActionManager *actions() const { return mpActionManager; }

signals:

private:
    QApplication *mpApplication=nullptr;
    ActionManager *mpActionManager;
};

