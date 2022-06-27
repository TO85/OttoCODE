QT += gui
QT *= widgets # for QMenu*

TEMPLATE = lib
DEFINES += OCQGUI_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useCore.pri)
include(../../useType.pri)
include(../../useExe.pri)

SOURCES += \
    BaseActionMenu.cpp \
    ocqGui.cpp

HEADERS += \
    ../../include/BaseActionMenu \
    BaseActionMenu.h \
    ocqGui_global.h \
    ocqGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
