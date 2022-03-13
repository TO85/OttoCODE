#pragma once
#include "ocqGui.h"

#include <QObject>

class QAction;

#include <KeyMap>
#include <QQString>
class Key;

class OCQGUI_EXPORT ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = nullptr);

public:
    bool contains(const Key &key) const;
    QAction *action(const Key &key) const;
    bool connectSlot(const Key &key, const QObject *actor,
                     const QByteArray &signature, const bool scanParents=false);

public slots:
    QAction *add(const Key &key, const QQString &text=QQString());
    void add(const Key &key, QAction *action);

public: // static
    static QMetaMethod method(const QObject *object, const QByteArray &signature, const bool scanParents=false);

signals:
    void actionAdded(const Key &key, QAction *action);

private:
    KeyMap<QAction *> mKeyActionMap;
};

