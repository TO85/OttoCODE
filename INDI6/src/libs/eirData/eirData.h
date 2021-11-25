#pragma once
#include "eirData_global.h"
#include "eirData-Qt5-pch.h"

#include <eirType/MultiName.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>
#include <eirType/QQVariant.h>
#include <eirXfr/Debug.h>

typedef MultiName Key;
typedef QList<Key> KeyList;
typedef QQVariant Value;
typedef QPair<Key, Value> Pair;
typedef QList<Pair> PairList;
typedef QMap<Key, Value> Map;

class EIRDATA_EXPORT eirData
{
public:
    eirData();
};
