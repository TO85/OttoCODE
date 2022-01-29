#pragma once

#include <QSharedDataPointer>

class FunctionInfoData;

class FunctionInfo
{
public:
    FunctionInfo();
    FunctionInfo(const FunctionInfo &);
    FunctionInfo &operator=(const FunctionInfo &);
    ~FunctionInfo();

private:
    QSharedDataPointer<FunctionInfoData> data;
};

