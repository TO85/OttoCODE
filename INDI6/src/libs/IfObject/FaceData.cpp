#include "FaceData.h"
DEFINE_DATAPROPS(FaceData, FaceDataData)
void FaceData::ctor(void) {;}
void FaceData::dtor(void) {;}

QQStringList FaceData::toDebugStrings() const
{
    return QQStringList()
            << QQString("{FaceResultItem:>")
            << getFaceResultItem().toDebugStrings()
            << QQString("<FaceResultItem}")
            << QQString("CroppedFaceImage = %1").arg(QQImage(getCroppedFaceImage()).toDebugString())
            << QQString("EyeMarkedFaceImage = %1").arg(QQImage(getEyeMarkedFaceImage()).toDebugString())
            << QQString("NormalizedFaceImage = %1").arg(QQImage(getNormalizedFaceImage()).toDebugString())
            << QQString("EyeROI = %1").arg(getEyeROI().toDebugString())
            << QQString("{LeftEyeResults:>")
            << getLeftEyeResults().toDebugStrings()
            << QQString("<LeftEyeResults}")
            << QQString("{RightEyeResults:>")
            << getRightEyeResults().toDebugStrings()
            << QQString("<RightEyeResults}");
}

QDebug operator << (QDebug dbg, const FaceData face)
{
    for (QQString s : face.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
