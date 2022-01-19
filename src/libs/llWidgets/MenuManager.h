#pragma once

#include <QObject>

class QMenu;
class QMenuBar;

#include <ActionManager>
#include <KeyMap>

class MenuManager : public QObject
{
    Q_OBJECT
public:
    explicit MenuManager(ActionManager *actions);

public:
    QMenuBar *bar() const;
    QMenu *menu(const Key &key) const;
    QAction *action(const Key &key) const;

public:
    QAction *add(const Key &key);
    void add(const Key &key, QAction *action);

signals:


private:
    ActionManager *mpActionManager=nullptr;
    QMenuBar *mpMenuBar=nullptr;
    KeyMap<QMenu *> mKeyMenuMap;
};

