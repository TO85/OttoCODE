#pragma once

#include <QQMainWindow>

class QListView;
class QTableView;

#include <QQMdiArea>
class SysEnvTableModel;
class SysPathListModel;

class EnvSubWin : public QQMdiArea
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

