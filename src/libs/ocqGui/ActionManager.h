#pragma once
#include "ocqGui.h"

#include <QObject>

#include <QAction>

#include <KeyMap>
class Key;

class OCQGUI_EXPORT ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = nullptr);

public:
    bool contains(const Key &key) const;
    QAction *action(const Key &key) const;

public slots:
    QAction *add(const Key &key, const QString &text=QString());
    void add(const Key &key, QAction *action);

signals:
    void actionAdded(const Key &key, QAction *action);

private:
    KeyMap<QAction *> mKeyActionMap;
};

