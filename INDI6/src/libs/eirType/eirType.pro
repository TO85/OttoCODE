QT -= gui ### ???QImage

TEMPLATE = lib
DEFINES += EIRTYPE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirType.pro)
include(../libs.pri)
include(../useBase.pri)

SOURCES += \
    Angle.cpp \
    BasicName.cpp \
    BasicNameMap.cpp \
    Boolean.cpp \
    BooleanString.cpp \
    CropRect.cpp \
    Denominators.cpp \
    DetectRect.cpp \
    DetectRectList.cpp \
    DetectRectMap.cpp \
    Enumeration.cpp \
    Line.cpp \
    Milliseconds.cpp \
    MultiName.cpp \
    MultiNameList.cpp \
    Null.cpp \
    ObjectType.cpp \
    PerMille.cpp \
    PolarPointF.cpp \
    QQBitArray.cpp \
    QQByteArray.cpp \
    QQByteArrayList.cpp \
    QQChar.cpp \
    QQDir.cpp \
    QQFileInfo.cpp \
    QQFileInfoList.cpp \
    QQLine.cpp \
    QQLineF.cpp \
    QQMetaType.cpp \
    QQPoint.cpp \
    QQPointF.cpp \
    QQRect.cpp \
    QQRectF.cpp \
    QQSize.cpp \
    QQSizeF.cpp \
    QQString.cpp \
    QQStringList.cpp \
    QQStringStdList.cpp \
    QQVariant.cpp \
    QQVariantList.cpp \
    QQtMsgType.cpp \
    Rational.cpp \
    SCRect.cpp \
    SCRectF.cpp \
    SCRectList.cpp \
    Slope.cpp \
    Sortable.cpp \
    StdStreams.cpp \
    StringTable.cpp \
    Success.cpp \
    WeightedAverageF.cpp \
    WeightedAverageR.cpp \
    eirType.cpp

HEADERS += \
    ../../resources/eirType/Primes1E6.hh \
    Angle.h \
    BasicName.h \
    BasicNameMap.h \
    Boolean.h \
    BooleanString.h \
    CropRect.h \
    Denominators.h \
    DetectRect.h \
    DetectRectList.h \
    DetectRectMap.h \
    DualMap.h \
    Enumeration.h \
    Line.h \
    ../MetaTypeShell.h \
    MatrixT.h \
    Milliseconds.h \
    MultiName.h \
    MultiNameList.h \
    Named.h \
    Null.h \
    ObjectType.h \
    PerMille.h \
    PolarPointF.h \
    QProperty.h \
    QQBitArray.h \
    QQByteArray.h \
    QQByteArrayList.h \
    QQChar.h \
    QQDir.h \
    QQFileInfo.h \
    QQFileInfoList.h \
    QQLine.h \
    QQLineF.h \
    QQList.h \
    QQMetaType.h \
    QQPoint.h \
    QQPointF.h \
    QQRect.h \
    QQRectF.h \
    QQSize.h \
    QQSizeF.h \
    QQString.h \
    QQStringList.h \
    QQStringStdList.h \
    QQVariant.h \
    QQVariantList.h \
    QQVector.h \
    QQtMsgType.h \
    Rational.h \
    SCRect.h \
    SCRectF.h \
    SCRectList.h \
    Slope.h \
    Sortable.h \
    StdStreams.h \
    StringTable.h \
    Success.h \
    WeightedAverageF.h \
    WeightedAverageR.h \
    eirType_global.h \
    eirType.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
