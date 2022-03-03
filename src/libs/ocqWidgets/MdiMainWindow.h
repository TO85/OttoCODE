#pragma once
#include "ocqWidgets.h"

#include <QtCore/QMap>

#include <Key>
#include <KeyMap>


#include <QQMainWindow>
#include <QQMdiArea>
class MdiGridWidget;
class MdiSubWinWidget;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QApplication *pApp);
    QQMdiArea *mdiArea() const;

public:
    MdiSubWinWidget *newSubWindow(const Key &key, const Qt::WindowFlags flags = Qt::WindowFlags());

public slots:
    void addSubWindow(MdiSubWinWidget *pSubWinWidget);

public slots: // actions
    virtual void windowTabbed();
    virtual void windowSubView();

private:
    QQMdiArea *mpMdiArea                                                                                                  ;
    KeyMap<MdiSubWinWidget *> mSubWinWidgetKeyMap;
};

