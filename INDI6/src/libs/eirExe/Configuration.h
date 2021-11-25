#pragma once
#include "eirExe.h"

#include <QtCore/QVariant>
#include <QtCore/QVariantMap>

#include <eirType/MultiName.h>

class EIREXE_EXPORT Configuration
{
public:
    typedef MultiName Key;
    typedef QVariant Value;

public:
    Configuration() {;}
    Configuration(const QVariantMap &map) : mMap(map) {;}
    Value value(const Key &key, Value defValue=Value());
    QVariantMap map() const { return mMap; }
    Configuration extract(const Key &groupKey, const Configuration &localConfig=Configuration()) const;

private:
     QVariantMap mMap;
};

