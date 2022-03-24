#include "FunctionInfoData.h"


void FunctionInfoData::process()
{
    const QString tQfiString = dmQFuncInfo;
    const int tOpenParen  = tQfiString.indexOf('(');
    const int tCloseParen = tQfiString.lastIndexOf(')');
    if ((tOpenParen < 1) || (tCloseParen < tOpenParen)) return;
    qDebug() << tQfiString << tQfiString.left(tOpenParen)
             << tQfiString.mid(tOpenParen, tCloseParen-tOpenParen)
             << tQfiString.mid(tCloseParen);
    dmQFuncInfoAnteParen = tQfiString.left(tOpenParen);
    dmQFuncInfoTwixParen = tQfiString.mid(tOpenParen, tCloseParen-tOpenParen);
    dmQFuncInfoPostParen = tQfiString.mid(tCloseParen);
    processAnteParen();
    processTwixParen();
    processPostParen();
    // NEEDDO more

}

void FunctionInfoData::processAnteParen()
{
    qDebug() << Q_FUNC_INFO << dmQFuncInfoAnteParen;
    const int lastColonPair = dmQFuncInfoAnteParen.lastIndexOf("::");
    const int lastSpaceAnteParen = dmQFuncInfoAnteParen.lastIndexOf(' ');
    dmClassName = dmQFuncInfoAnteParen.mid(lastSpaceAnteParen+1, lastColonPair-lastSpaceAnteParen);
    dmFunctionName = dmQFuncInfoAnteParen.mid(lastColonPair+2);
    qDebug() << dmClassName << dmFunctionName;
    Q_ASSERT(false); // MUSTDO it
}

void FunctionInfoData::processTwixParen()
{
    qDebug() << Q_FUNC_INFO << dmQFuncInfoTwixParen;
    Q_ASSERT(false); // MUSTDO it
}

void FunctionInfoData::processPostParen()
{
    qDebug() << Q_FUNC_INFO << dmQFuncInfoPostParen;
    Q_ASSERT(false); // MUSTDO it
}

