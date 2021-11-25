#pragma once

#include <QtCore/QObject>

#include <QtCore/QMap>
class QAction;
class QIcon;

#include <eirType/DualMap.h>
#include <eirType/MultiName.h>
#include <eirType/QQString.h>

class ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = nullptr);

public: // enquiry
    QAction *action(const MultiName &aName);

public: // commands
    void add(const MultiName &aName, QAction * pAction);
    QAction *add(const MultiName &aName);
    QAction *add(const MultiName &aName, const QQString &aText);
    QAction *add(const MultiName &aName, const QIcon &aIcon, const QQString &aText);

signals:

private:
    DualMap<MultiName, QAction *> mNameActionDMap;
};

