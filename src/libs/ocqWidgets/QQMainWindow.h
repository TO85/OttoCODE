#pragma once
#include "ocqWidgets.h"

#include <QMainWindow>

class QApplication;
class QCoreApplication;
class QMenu;

#include <KeyMap>
#include <QQString>
class ActionManager;
class Key;

class OCQWIDGETS_EXPORT QQMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QQMainWindow(QApplication *pApp);
    const QApplication *gui() const;
    const QCoreApplication *core() const;
    const QObject *object();
    ActionManager *actions() const;
    QAction *action(const Key key);
    QMenu * menu(const Key key);

public:
    QMenu * addMenu(const Key key, const QQString &text=QQString());

public slots:
    void setup();
    void exit();

signals:
    void setupComplete();

protected:
    virtual void setupStart();
    virtual void setupActions();
    virtual void setupConnections();
    virtual void setupMenus();
    virtual void setupToolbars();
    virtual void setupWidgets();
    virtual void setupFinish();

private:
    QApplication *mpApplication=nullptr;
    ActionManager *mpActionManager=nullptr;
    KeyMap<QMenu *> mKeyMenuMap;
};

