QT -= gui
QT *= network

TEMPLATE = lib
DEFINES += EIRBASE_LIBRARY

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

message(================In eirBase.pro)
include(../libs.pri)

SOURCES += \
    UInt128.cpp \
    Uid.cpp \
    VersionInfo.cpp \
    eirBase.cpp

HEADERS += \
    UInt128.h \
    QtTypes.h \
    Uid.h \
    VersionInfo.h \
    eirBase_global.h \
    eirBase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../.gitignore \
    ../../resources/hosts/Monarch.bat \
    ../../resources/hosts/Titan.sh
