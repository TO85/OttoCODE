#pragma once
#include "ocqWidgets.h"

#include <QMdiArea>

class QMainWindow;

class MdiSubWinWidget;

class OCQWIDGETS_EXPORT QQMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    QQMdiArea(QMainWindow *pMain);
    void addSubWinWidget(const MdiSubWinWidget *pSubWinWidget);

};

