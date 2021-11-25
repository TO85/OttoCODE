QT += gui
QT *= xml

TEMPLATE = lib
DEFINES += IFMANAGER_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In IfManager.pro)
include(../libs.pri)
PRECOMPILED_HEADER = ./IfManager-Qt5-pch.h
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useXml.pri)
include(../useGeometry.pri)
include(../useIfData.pri)

SOURCES += \
    INDIfaceManager.cpp \
    IfManager.cpp \
    ImageFactory.cpp

HEADERS += \
    INDIfaceManager.h \
    IfManager_global.h \
    IfManager.h \
    ImageFactory.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
