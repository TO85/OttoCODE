#pragma once
#include "ocqWidgets.h"

#include <QMdiSubWindow>

#include <QWidget>

#include <Key>
class QQMdiArea;
class QQGridLayout;

class OCQWIDGETS_EXPORT hold-MdiGridSubWin : public QMdiSubWindow
{
    Q_OBJECT
public:
    hold-MdiGridSubWin(const Key & key, QQMdiArea *parent,
                    Qt::WindowFlags flags = Qt::WindowFlags());
    QQMdiArea * mdiArea();
    QQGridLayout * grid();
    QWidget * gridWidget();
    Key key() const { return mKey; }
    virtual QString title() const = 0;

public slots:
    virtual void setup();

private:
    QQMdiArea *mpMdiArea=nullptr;
    Key mKey;
    QQGridLayout * mpGridLayout=nullptr;
    QWidget * mpGridWidget=nullptr;
};

