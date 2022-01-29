#pragma once
#include "ocqWidgets.h"

#include <QMainWindow>

class QApplication;

class ActionManager;
class MenuManager;

class OCQWIDGETS_EXPORT QQMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QQMainWindow(QApplication *pApp);
    const QApplication *gui() const { return mpApplication; }
    ActionManager *actions() const { return mpActionManager; }
    MenuManager *menus() const { return mpMenuManager; }

public slots:
    void setup();

signals:
    void setupComplete();

protected:
    virtual void setupStart();
    virtual void setupMenus();
    virtual void setupActions();
    virtual void setupConnections();
    virtual void setupWidgets();
    virtual void setupFinish();

private:
    QApplication *mpApplication=nullptr;
    ActionManager *mpActionManager=nullptr;
    MenuManager *mpMenuManager=nullptr;
};

