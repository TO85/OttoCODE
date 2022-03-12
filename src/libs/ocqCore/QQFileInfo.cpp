#include "QQFileInfo.h"


bool operator == (const QQFileInfo &lfi, const QQFileInfo &rfi)
{
    return lfi.absoluteFilePath() == rfi.absoluteFilePath();
}

bool operator <  (const QQFileInfo &lfi, const QQFileInfo &rfi)
{
    return lfi.absoluteFilePath() <  rfi.absoluteFilePath();
}
