QT += gui

TEMPLATE = lib
DEFINES += OCQGUI_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    ActionManager.cpp \
    ocqGui.cpp

HEADERS += \
    ActionManager.h \
    ocqGui_global.h \
    ocqGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
