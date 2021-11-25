#QT -= gui ###QImage
QT *= xml

TEMPLATE = lib
DEFINES += INDIFACE_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

message(================In INDIface.pro)
include(../libs.pri)
PRECOMPILED_HEADER = ./INDIface-Qt5-pch.h
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useXml.pri)
include(../useGeometry.pri)
include(../useIfData.pri)

SOURCES += \
    INDIface.cpp \
    INDIfaceManager.cpp

HEADERS += \
    INDIface-Qt5-pch.h \
    INDIfaceManager.h \
    INDIface_global.h \
    INDIface.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
