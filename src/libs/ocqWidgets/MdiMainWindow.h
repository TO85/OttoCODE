#pragma once
#include "ocqWidgets.h"

#include <QtCore/QMap>

#include <Key>
#include <KeyMap>


#include <QQMainWindow>
#include <QQMdiArea>
class MdiGridWindow;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QApplication *pApp);
    QQMdiArea *mdiArea() const;

public slots:
    void addSubWindow(MdiGridWindow *pSubWindow);

public slots: // actions
    void windowTabbed();
    void windowSubView();

private:
    QQMdiArea *mpMdiArea                                                                                                  ;
    KeyMap<MdiGridWindow *> mSubWindowKeyMap;
};

