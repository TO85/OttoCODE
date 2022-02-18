#pragma once
#include "ocqWidgets.h"

#include <QWidget>

#include <Key>
class QQMdiArea;

class OCQWIDGETS_EXPORT MdiSubWinWidget : public QWidget
{
    Q_OBJECT
public:
    MdiSubWinWidget(const Key & key, QQMdiArea *parent = nullptr,
                    Qt::WindowFlags flags = Qt::WindowFlags());
    QQMdiArea *mdiArea();
    Key key() const { return mKey; }

public slots:
    virtual void setup();

private:
    QQMdiArea *mpMdiArea=nullptr;
    Key mKey;
};

