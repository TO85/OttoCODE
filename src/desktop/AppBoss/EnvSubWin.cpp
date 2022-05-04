#include "EnvSubWin.h"

#include <QLabel>
#include <QListView>
#include <QTableView>

#include <MdiGridSubWin>
#include <QQGridLayout>
#include <QQMdiArea>
#include <SysEnvTableModel>
#include <SysPathListModel>

EnvSubWin::EnvSubWin(QQMdiArea *parent, Qt::WindowFlags flags)
    : MdiGridSubWin("SysEnv", parent, flags)
    , mpSysEnvModel(new SysEnvTableModel(this))
    , mpSysPathModel(new SysPathListModel(this))
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpSysEnvModel);
    Q_CHECK_PTR(mpSysPathModel);
    setObjectName("EnvSubWin");
    qDebug() << Q_FUNC_INFO << mdiArea()->objectName() << objectName();
}

void EnvSubWin::setup()
{
    Q_CHECK_PTR(this);
    enum { EnvVarLabelRow, EnvBarTableRow, SpacingRow, PathLabelRow, PathListViewRow };
    enum { LeftMarginCol, TitleViewCol };
    Q_CHECK_PTR(mpSysEnvModel);
    Q_CHECK_PTR(mpSysPathModel);
    QLabel *pEnvLabel = new QLabel(tr("System Environment Values", "Title"), this);
    QLabel *pPathLabel = new QLabel(tr("Executable Path Directories", "Title"), this);
    Q_CHECK_PTR(pEnvLabel);
    Q_CHECK_PTR(pPathLabel);
    mpKeyValueTableView = new QTableView(this);
    mpPathListView = new QListView(this);
    Q_CHECK_PTR(mpKeyValueTableView);
    Q_CHECK_PTR(mpPathListView);
    grid()->addWidget(pEnvLabel, EnvVarLabelRow, TitleViewCol);
    grid()->addWidget(mpKeyValueTableView, EnvBarTableRow, TitleViewCol);
    grid()->addWidget(pPathLabel, PathLabelRow, TitleViewCol);
    grid()->addWidget(mpPathListView, PathListViewRow, TitleViewCol);
    MdiGridSubWin::setup();
//    for (int row = 0; row < mpSysEnvModel->rowCount(); ++row)
  //      mpKeyValueTableView->setRowHeight(row, 10); TODO: Didn't work
    // TODO: Headings
    // TODO: Get rid of selection boxes
    mpKeyValueTableView->setColumnWidth(0, 200);
    mpKeyValueTableView->setColumnWidth(1, 500);
    mpKeyValueTableView->setWordWrap(false);
    mpKeyValueTableView->setModel(mpSysEnvModel);
    mpPathListView->setModel(mpSysPathModel);
}
