#pragma once

#include <QObject>

#include <QTimer>
class QAction;

#include <Key>
#include <KeyMap>

class BaseActions : public QObject
{
    Q_OBJECT
public:
    explicit BaseActions(QObject *parent = nullptr);

public:
    bool contains(const Key keyName) const;
    QAction * action(const Key keyName) const;

public:
    QAction * add(const Key keyName);
    void add(const Key keyName, QAction * pAction);

public slots:
    void openFrameFile() {;}
    void openFrameDir() {;}
    void openSequenceFile() {;}

signals:
    void added(const Key, const QAction *);

private:
    KeyMap<QAction *> mKeyActionMap;
};

