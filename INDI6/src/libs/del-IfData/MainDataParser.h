#pragma once

#include "AbstractParser.h"

#include "MainResource.h"

class MainDataParser : public AbstractParser
{
public:
    MainDataParser() {;}

public:
    virtual void clear() override;
    virtual DomStatus load(const QQDomElement &de) override;
    MainResource mainData() const { return mMainData; }

private:
    virtual QQString doctypeExpected() const override;
    virtual QQString dataTagExpected() const override;

public:
    virtual QQStringList toDebugStrings() const override { return mMainData.toDebugStrings(); }

private:
    MainResource mMainData;
};

