#pragma once
#include "ocqWidgets.h"

#include "QQMdiSubWindow.h"

#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>

#include <Key>

#include "QQMdiArea.h"

class OCQWIDGETS_EXPORT MdiGridWindow : public QQMdiSubWindow
{
    Q_OBJECT
public:
    MdiGridWindow(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());
    Key key() const { return mKey; }
    QGridLayout *layout() const;

public slots:
    virtual void setup();


protected:

private:
    QGridLayout *mpGridLayout=nullptr;
    Key mKey;
};

