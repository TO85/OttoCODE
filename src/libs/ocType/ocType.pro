QT -= gui

TEMPLATE = lib
DEFINES += OCTYPE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    CommaString.cpp \
    ocType.cpp

HEADERS += \
    CommaString.h \
    DualMap.h \
    ocType_global.h \
    ocType.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
