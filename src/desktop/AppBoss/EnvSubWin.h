#pragma once

#include <MdiGridSubWin>

class QListView;
class QTableView;

class QQMdiArea;
class SysEnvTableModel;
class SysPathListModel;

class EnvSubWin : public MdiGridSubWin
{
    Q_OBJECT
public:
    EnvSubWin(QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());

    virtual QString title() const { return "System Environment Values"; }

public slots:
    virtual void setup();

private slots:

private:
    SysEnvTableModel *mpSysEnvModel=nullptr;
    SysPathListModel *mpSysPathModel=nullptr;
    QTableView *mpKeyValueTableView=nullptr;
    QListView *mpPathListView=nullptr;
};

