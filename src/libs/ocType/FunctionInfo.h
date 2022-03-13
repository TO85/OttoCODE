#pragma once

#include <QSharedDataPointer>

class FunctionInfoData;

class FunctionInfo
{
public:
    FunctionInfo();
    FunctionInfo(const char * psz);
    FunctionInfo(const QString & qs);
    FunctionInfo(const FunctionInfo &);
    FunctionInfo &operator=(const FunctionInfo &);
    ~FunctionInfo();

public:
    void set(const char * psz) { set(QString(psz)); }
    void set(const QString & qs);
    void process();

protected:
    void processAnteParen(const QString &qs);
    void processTwixParen(const QString &qs);
    void processPostParen(const QString &qs);

private:
    QSharedDataPointer<FunctionInfoData> data;
};

