#pragma once
#include "ocqWidgets.h"

#include <QtCore/QMap>

#include <Key>
#include <KeyMap>


#include <QQMainWindow>
#include <QQMdiArea>
class MdiGridWidget;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QApplication *pApp);
    QQMdiArea *mdiArea() const;

public slots:
    void addSubWindow(MdiGridWidget *pSubWinWidget);

public slots: // actions
    virtual void windowTabbed();
    virtual void windowSubView();

private:
    QQMdiArea *mpMdiArea                                                                                                  ;
    KeyMap<MdiGridWidget *> mSubWinWidgetKeyMap;
};

