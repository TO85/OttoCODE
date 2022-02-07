QT -= gui

TEMPLATE = lib
DEFINES += OCQCORE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    ObjectHelper.cpp \
    QQDir.cpp \
    QQFileInfo.cpp \
    ocqCore.cpp

HEADERS += \
    ../../include/QQDir \
    ObjectHelper.h \
    QQDir.h \
    QQFileInfo.h \
    ocqCore_global.h \
    ocqCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
