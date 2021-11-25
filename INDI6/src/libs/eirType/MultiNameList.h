#pragma once
#include "eirType.h"

#include "MultiName.h"
#include "QQStringList.h"

class MultiNameList : public MultiName::List
{
public:
    MultiNameList() {;}
    MultiNameList(const QList<MultiName> aNames);

public:
    QQStringList toStringList() const;
    QStringList toQStringList() const;
    QString toQString(const QString &sep);
    QString operator () () { return toQString(";"); }

private:
    MultiNameList &it() { return *this; }
    MultiNameList it() const { return *this; }
};

