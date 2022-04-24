# QT -= gui

TEMPLATE = lib
DEFINES += LLEXE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    CommandLine.cpp \
    SysEnvTableModel.cpp \
    SysPathListModel.cpp \
    SysProcessEnv.cpp \
    ocExe.cpp

HEADERS += \
    ../../include/CommandLine \
    ../../include/SysEnvTableModel \
    ../../include/SysPathListModel \
    CommandLine.h \
    SysEnvTableModel.h \
    SysPathListModel.h \
    SysProcessEnv.h \
    ocExe_global.h \
    ocExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
