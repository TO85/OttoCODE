#pragma once
#include "ocqWidgets.h"

#include <QMdiArea>

#include <QMdiSubWindow>

#include <KeyMap>

class QQMainWindow;

class OCQWIDGETS_EXPORT QQMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    QQMdiArea(QQMainWindow *pMain);
    QQMainWindow * mainWindow();

public:
    bool contains(const Key &key);

public slots:
    void registerSubWin(QMdiSubWindow *pSubWin);

private:
    QQMainWindow * mpMainWindow=nullptr;
    KeyMap<QMdiSubWindow *> mKeySubWindowMap;
};

