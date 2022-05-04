#pragma once
#include "ocqWidgets.h"

#include "QQMainWindow.h"

#include <QtCore/QMap>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include <Key>
#include <KeyMap>
#include <QQFileInfo>

class hold-MdiDocument;
class MdiGridWidget;
class hold-MdiGridSubWin;
class QQMdiArea;

class OCQWIDGETS_EXPORT hold-MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    hold-MdiMainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    QObject * object();
    QQMdiArea * mdiArea() const;

public:
    void add(const QQFileInfo &fileInfo);
    void add(hold-MdiGridSubWin *pSubWinWidget);

public slots:

protected slots:
    virtual void setupActions();
    virtual void setupConnections();


public slots: // actions
    virtual void windowTabbed();
    virtual void windowSubView();

private:
    QQMdiArea *mpMdiArea;
    QMap<QQFileInfo, QMdiSubWindow *> mFileSubWindowMap;
    KeyMap<hold-MdiGridSubWin *> mSubWinWidgetKeyMap;
};

