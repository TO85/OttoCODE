#pragma once
#include "ocqWidgets.h"

#include <QMdiSubWindow>

class QQMdiArea;

class OCQWIDGETS_EXPORT QQMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    QQMdiSubWindow(QQMdiArea *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    QQMdiArea *mdiArea();

public slots:
    virtual void setup();

private:
    QQMdiArea *mpMdiArea=nullptr;
};

