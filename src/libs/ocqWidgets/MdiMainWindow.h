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
class MdiSubWinWidget;
class QQMdiArea;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    QObject * object();
    QQMdiArea * mdiArea() const;

public:
    MdiSubWinWidget * newSubWindow(const Key &key, const Qt::WindowFlags flags);
    void add(const QQFileInfo &fi, MdiDocument *pDoc);
    void add(MdiSubWinWidget *pSubWinWidget);

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
    QMap<QQFileInfo, MdiDocument *> mFileInfoDocumentMap;
    KeyMap<MdiSubWinWidget *> mSubWinWidgetKeyMap;
};

