#pragma once
#include "eirSql.h"

#include <QtCore/QObject>

#include <QtCore/QMap>

#include <eirType/BasicName.h>
#include <eirType/Boolean.h>

class EIRSQL_EXPORT SqlManager : public QObject
{
    Q_OBJECT
public:
    explicit SqlManager();

public slots:
    void initialize();

private slots:
    void initializeConnectors();

signals:
    void constructed();
    void initialized();

private:
    Boolean mInitialized;
    QMap<BasicName, QQString> mConnectorDescroptionMap;
};

Q_GLOBAL_STATIC(SqlManager, SQL);

