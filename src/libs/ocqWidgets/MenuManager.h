#pragma once

#include <QObject>

class QAction;
class QApplication;
class QMenu;
class QMenuBar;

//#include <ActionManager>
#include <KeyMap>
class ActionManager;
class QQMainWindow;

class MenuManager : public QObject
{
    Q_OBJECT
public:
    explicit MenuManager(QQMainWindow *main, ActionManager *actions, QObject *parent);

public:
    QQMainWindow *main() const;
    QMenuBar *bar() const;
    QMenu *menu(const Key &key) const;
    QAction *action(const Key &key) const;

public:
    QAction *add(const Key &key);
    bool add(const Key &key, QAction *action);

signals:


private:
    QQMainWindow *mpMainWindow=nullptr;
    ActionManager *mpActionManager=nullptr;
    QMenuBar *mpMenuBar=nullptr;
    KeyMap<QMenu *> mKeyMenuMap;
};

