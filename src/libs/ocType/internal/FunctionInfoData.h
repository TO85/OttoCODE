#pragma once
#include "ocType.h"

#include <QStringList>

#include <Millisecond>
#include <QQFileInfo>
#include <QQString>
#include <Uid>

class FunctionInfoData : public QSharedData
{
private:
    friend class FunctionInfo;
    void process();
    void processAnteParen();
    void processTwixParen();
    void processPostParen();

private:
    QFileInfo dmFuncFileInfo;
    int dmFuncFileLine;
    QQString dmQFuncInfo;
    QQString dmQFuncInfoAnteParen;
    QQString dmQFuncInfoTwixParen;
    QQString dmQFuncInfoPostParen;
    QQString dmClassName;
    QQString dmFunctionName;
    QStringList dmArgNames;
    // TODO more
};
