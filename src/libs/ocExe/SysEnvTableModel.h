#pragma once
#include "ocExe.h"

#include <QAbstractTableModel>

#include <QSize>

#include <QFont>
#include <QModelIndex>
#include <QVariant>

#include "SysProcessEnv.h"

class OCEXE_EXPORT SysEnvTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum ColEnum { $nullCOl = -1, KeyCol = 0, ValueCol, $sizeCol };

public:
    explicit SysEnvTableModel(QObject *parent = nullptr);

public:
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    QSize mCountSize=QSize(0,0);
    QFont mKeyFont=QFont("Courier", 10, 300);
    QFont mValueFont=QFont("Helvetica", 10);
};

