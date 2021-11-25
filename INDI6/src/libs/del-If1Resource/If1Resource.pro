QT *= gui
QT *= xml

TEMPLATE = lib
DEFINES += IF1RESOURCE_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In If1Resource.pro)
include(../libs.pri)

PRECOMPILED_HEADER = ./If1Resource-Qt5-pch.h
include(../useType.pri)
include(../useXml.pri)
include(../useGui.pri)
include(../useGeometry.pri)

SOURCES += \
    BaseDocument.cpp \
    If1Resource.cpp \
    MainData.cpp \
    MainDocument.cpp \
    Resource1BaseData.cpp \
    Resource1Data.cpp \
    Resource1Loader.cpp

HEADERS += \
    ./If1Resource-Qt5-pch.h \
    BaseDocument.h \
    If1Resource_global.h \
    If1Resource.h \
    MainData.h \
    MainDocument.h \
    Resource1BaseData.h \
    Resource1Data.h \
    Resource1Loader.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


DISTFILES += \
    ../../resources/data/Face1/BitMask.xml \
    ../../resources/data/Face1/Face1.xml \
    ../../resources/data/Face1/FaceLayers.xml \
    ../../resources/data/Face1/MeanFace.xml \
    ../../resources/data/Face1/WeightMask.xml
