#pragma once
#include "ocqWidgets.h"

#include <QMdiArea>

#include <KeyMap>

class QQMainWindow;

class hold-MdiGridSubWin;

class OCQWIDGETS_EXPORT QQMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    QQMdiArea(QQMainWindow *pMain);
    QQMainWindow * mainWindow();
    hold-MdiGridSubWin * subWin(const Key & key);

public:
    bool contains(const Key &key);

public slots:
    void registerSubWin(hold-MdiGridSubWin *pSubWin);

private:
    QQMainWindow * mpMainWindow=nullptr;
    KeyMap<hold-MdiGridSubWin *> mKeySubWinMap;
};

