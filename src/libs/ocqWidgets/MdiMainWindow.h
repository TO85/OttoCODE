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

class MdiDocument;
class MdiGridWidget;
class MdiGridSubWin;
class QQMdiArea;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    QObject * object();
    QQMdiArea * mdiArea() const;

public:
    void add(const QQFileInfo &fileInfo);
    void add(MdiGridSubWin *pSubWinWidget);

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
    KeyMap<MdiGridSubWin *> mSubWinWidgetKeyMap;
};

