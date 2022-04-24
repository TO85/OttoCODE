#include "SysEnvTableModel.h"

#include <QBrush>

#include <KeySegList>

Q_GLOBAL_STATIC(SysProcessEnv, gspSysProcessEnv);


SysEnvTableModel::SysEnvTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    Q_CHECK_PTR(this);
    setObjectName("SysEnvTableModel");
    qDebug() << Q_FUNC_INFO << objectName();
    mCountSize = QSize($sizeCol, gspSysProcessEnv->keyCount());
}

QVariant SysEnvTableModel::data(const QModelIndex &index, int role) const
{
    Q_CHECK_PTR(this);
    QVariant result;
    const bool tIsKey = 0 == index.column();
    const QString tDisplay = tIsKey
                                ? gspSysProcessEnv->key(index.row()).toQString()
                                : gspSysProcessEnv->value(index.row());
    switch (role)
    {
    case Qt::FontRole:              result.setValue(tIsKey
                                                    ? mKeyFont
                                                    : mValueFont);          break; // 6
    case Qt::TextAlignmentRole:     result.setValue(tIsKey
                                                    ? Qt::AlignRight
                                                    : Qt::AlignLeft);       break; // 7
    case Qt::ForegroundRole:        result.setValue(QBrush(Qt::black));     break; // 9
    case Qt::CheckStateRole:        result.setValue(Qt::Unchecked);         break; // 10
    case Qt::DisplayRole:           result.setValue(tDisplay);              break; // 0
    case Qt::BackgroundRole:        result.setValue(QBrush(Qt::white));     break; // 8
    case Qt::DecorationRole:        Q_FALLTHROUGH();                               // 1
    default:                        /* let null QVariant result ride */     break;
    }
    qDebug() << Q_FUNC_INFO << index.row() << index.column() << role << tIsKey << tDisplay << result;
    return result;
}

int SysEnvTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCountSize.width();
}

int SysEnvTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCountSize.height();
}
