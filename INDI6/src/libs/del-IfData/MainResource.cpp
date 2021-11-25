#include "MainResource.h"


void MainResource::clear()
{
    mName.clear();
    mClassName.clear();
    mDescription.clear();
    mActivePixels = 0;
    mNormalSize.nullify();
    mNormalEyeLine.nullify();
}

QQStringList MainResource::toDebugStrings() const
{
    QQStringList result;
    result << "{Indi1MainData:>";
    result << "Name =" << mName();
    result << "ClassName =" << mClassName();
    result << "Description =" << mDescription();
    result << "ActivePixels = " << mActivePixels;
    result << "NormalSize = " << mNormalSize.toDebugString();
    result << "NormalEyeLine = " << mNormalEyeLine.toDebugString();
    result << "<Indi1MainData}";
    return result;
}
