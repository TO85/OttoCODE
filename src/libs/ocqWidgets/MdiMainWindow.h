#pragma once
#include "ocqWidgets.h"

#include <QtCore/QMap>

#include <Key>
#include <KeyMap>
#include <QQFileInfo>

#include <QQMainWindow>
#include <QQMdiArea>
class MdiDocument;
class MdiGridWidget;
class MdiSubWinWidget;

//#include "MdiDocument.h"
class MdiDocument;

class OCQWIDGETS_EXPORT MdiMainWindow : public QQMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QApplication *pApp);
    QObject *object();
    QQMdiArea *mdiArea() const;

public:
    MdiSubWinWidget * newSubWindow(const Key &key, const Qt::WindowFlags flags = Qt::WindowFlags());

public slots:
    void add(const QQFileInfo &fi, MdiDocument * pDoc);
    void add(MdiSubWinWidget *pSubWinWidget);

protected slots:
    virtual void setupActions();
    virtual void setupConnections();


public slots: // actions
    virtual void windowTabbed();
    virtual void windowSubView();

private:
    QQMdiArea *mpMdiArea;
    QMap<QQFileInfo, MdiDocument *> mFileInfoDocumentMap;
    KeyMap<MdiSubWinWidget *> mSubWinWidgetKeyMap;
};

