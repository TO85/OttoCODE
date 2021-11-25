#pragma once
#include "IfData.h"

class AbstractParser
{
public:
    AbstractParser();

public:
    virtual void clear() = 0;
    virtual DomStatus load(const QQDomElement &de) = 0;

private:
    virtual QQString doctypeExpected() const = 0;
    virtual QQString dataTagExpected() const = 0;

public:
    virtual QQStringList toDebugStrings() const = 0;
    void dump() const { for (auto s : toDebugStrings().list()) DUMP << s; }


};

