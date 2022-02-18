#pragma once
#include "ocqWidgets.h"

#include "MdiSubWinWidget.h"

#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>

#include <Key>

#include "QQMdiArea.h"

class OCQWIDGETS_EXPORT MdiGridWidget : public MdiSubWinWidget
{
    Q_OBJECT
public:
    MdiGridWidget(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());
    Key key() const { return mKey; }
    QGridLayout *layout() const;

public slots:
    virtual void setup();


protected:

private:
    QGridLayout *mpGridLayout=nullptr;
    Key mKey;
};

