#pragma once
#include "ocExe.h"

#include <QAbstractListModel>

#include <QModelIndex>
#include <QSize>
#include <QFont>
#include <QVariant>

#include "SysProcessEnv.h"

class OCEXE_EXPORT SysPathListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SysPathListModel(QObject *parent = nullptr);

public:
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:

signals:

private:
    QSize mCountSize=QSize(0,0);
    QFont mFont=QFont("Courier", 10, 300);


};

