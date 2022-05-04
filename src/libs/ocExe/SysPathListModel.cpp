#include "SysPathListModel.h"

#include <QBrush>

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
    if (0 != index.column()) return result;                         /* /====\ */
    const QQDir tCurrentDir = gspSysProcessEnv->pathDir(index.row());
    const QString tCurrentPath = tCurrentDir.absolutePath();
    const bool tExists = tCurrentDir.exists();
    QFont tFont = mFont;
    tFont.setFixedPitch(true);
    tFont.setItalic( ! tExists);
    tFont.setWeight(tExists ? QFont::Normal : QFont::ExtraLight);

    switch (role)
    {
    case Qt::FontRole:              result.setValue(tFont);                 break; // 6
    case Qt::TextAlignmentRole:     result.setValue(Qt::AlignLeft);         break; // 7
    case Qt::ForegroundRole:        result.setValue(QBrush(Qt::black));     break; // 9
    case Qt::CheckStateRole:        result.setValue(Qt::Unchecked);         break; // 10
    case Qt::DisplayRole:           result.setValue(tCurrentPath);          break; // 0
    case Qt::BackgroundRole:        result.setValue(QBrush(tExists
                                                       ? Qt::white
                                                       : Qt::lightGray));   break; // 8
    case Qt::DecorationRole:        Q_FALLTHROUGH();                               // 1
    default:                        /* let null QVariant result ride */     break;
    }

    qDebug() << Q_FUNC_INFO << index.row() << index.column() << role
             << tCurrentPath << tExists << result;
    return result;
}
/*
QVariant SysEnvTableModel::data(const QModelIndex &index, int role) const
{
    Q_CHECK_PTR(this);
    QVariant result;
    const bool tIsKey = 0 == index.column();
    const QString tDisplay = tIsKey
                                ? gspSysProcessEnv->key(index.row()).toQString()
                                : gspSysProcessEnv->value(index.row());
    qDebug() << Q_FUNC_INFO << index.row() << index.column() << role << tIsKey << tDisplay << result;
    return result;
}


 */
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

