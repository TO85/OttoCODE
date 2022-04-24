#pragma once
#include "ocqWidgets.h"

#include <QMdiArea>

#include <KeyMap>

class QQMainWindow;

class MdiGridSubWin;

class OCQWIDGETS_EXPORT QQMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    QQMdiArea(QQMainWindow *pMain);
    QQMainWindow * mainWindow();
    MdiGridSubWin * subWin(const Key & key);

public:
    bool contains(const Key &key);

public slots:
    void registerSubWin(MdiGridSubWin *pSubWin);

private:
    QQMainWindow * mpMainWindow=nullptr;
    KeyMap<MdiGridSubWin *> mKeySubWinMap;
};

