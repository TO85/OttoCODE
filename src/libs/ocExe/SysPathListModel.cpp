#include "SysPathListModel.h"

Q_GLOBAL_STATIC(SysProcessEnv, gspSysProcessEnv);

SysPathListModel::SysPathListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    mCountSize = QSize(1, gspSysProcessEnv->pathCount());
}

QVariant SysPathListModel::data(const QModelIndex &index, int role) const
{
    Q_CHECK_PTR(this);
    QVariant result;
    if (0 == index.column())
        result = gspSysProcessEnv->pathDir(index.row()).toVariant();
    qDebug() << Q_FUNC_INFO << index.row() << index.column() << role << result;
    return result;
}

int SysPathListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCountSize.width();
}

int SysPathListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCountSize.height();
}

