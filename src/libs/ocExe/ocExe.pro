# QT -= gui

TEMPLATE = lib
DEFINES += LLEXE_LIBRARY

message(================In eirExe.pro)
include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)

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
