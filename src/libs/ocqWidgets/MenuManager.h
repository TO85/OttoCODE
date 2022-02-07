#pragma once

#include <QObject>

class QAction;
class QApplication;
class QMenu;
class QMenuBar;

#include <Key>
#include <KeyMap>
#include <String>
class ActionManager;
class QQMainWindow;

template class KeyMap<QMenu*>;

class MenuManager : public QObject
{
    Q_OBJECT
public:
    explicit MenuManager(QQMainWindow *main, ActionManager *actions, QObject *parent);

public:
    QQMainWindow *main() const;
    QMenuBar *bar() const;
    QMenu *menu(const Key &key) const;
    ActionManager *actions() const;
    QAction *action(const Key &key) const;

public:
    QMenu *addPrimary(const Key &key, const String &text=String());
    QAction *add(const Key &key, const String &text=String());
    bool add(const Key &key, QAction *action);

signals:


private:
    QQMainWindow *mpMainWindow=nullptr;
    ActionManager *mpActionManager=nullptr;
    QMenuBar *mpMenuBar=nullptr;
    KeyMap<QMenu *> mKeyMenuMap;
};

