#pragma once

#include <QObject>
#include "del-ResourceData.h"

#include <eirType/QQDir.h>
#include <eirType/QQString.h>

class ResourceLoader : public QObject, public ResourceData
{
    Q_OBJECT
public:
    explicit ResourceLoader(QObject *parent = nullptr);
    explicit ResourceLoader(const QQString &aBaseDirName, QObject *parent = nullptr);

public:
    bool setBaseDir(const QQString &aBaseDirName);

signals:

private:
    QQDir mBaseDir;

};

