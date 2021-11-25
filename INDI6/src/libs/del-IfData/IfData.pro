QT *= gui
QT *= xml

TEMPLATE = lib
DEFINES += IFDATA_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
PRECOMPILED_HEADER = ./IfData-Qt5-pch.h
include(../useType.pri)
include(../useXml.pri)
include(../useGui.pri)
include(../useGeometry.pri)

SOURCES += \
    AbstractParser.cpp \
    BaseINDI1BitMask.cpp \
    BaseIndi1MaskedFloatVector.cpp \
    BaseResourceObject.cpp \
    IfData.cpp \
    InputIndi1BitMask.cpp \
    LayerIndi1MaskedFloatVector.cpp \
    MainDataParser.cpp \
    MainResource.cpp \
    MeanFaceIndi1MaskedFloatVector.cpp \
    OutputIndi1BitMask.cpp \
    ResourceData.cpp \
    ResourceInterface.cpp \
    ResourceManager.cpp \
    VectorLayerData.cpp \
    VectorLayerSet.cpp \
    WeightMaskIndi1MaskedFloatVector.cpp

HEADERS += \
    AbstractParser.h \
    BaseINDI1BitMask.h \
    BaseIndi1MaskedFloatVector.h \
    BaseResourceObject.h \
    IfData-Qt5-pch.h \
    IfData_global.h \
    IfData.h \
    InputIndi1BitMask.h \
    LayerIndi1MaskedFloatVector.h \
    MainDataParser.h \
    MainResource.h \
    MeanFaceIndi1MaskedFloatVector.h \
    OutputIndi1BitMask.h \
    ResourceData.h \
    ResourceInterface.h \
    ResourceManager.h \
    VectorLayerData.h \
    VectorLayerSet.h \
    WeightMaskIndi1MaskedFloatVector.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
