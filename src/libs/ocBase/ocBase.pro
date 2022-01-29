QT -= gui

TEMPLATE = lib
DEFINES += TOBASE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
#    AbstractString.cpp \
 #   BaseString.cpp \
    AsciiChar.cpp \
    AsciiString.cpp \
    Error.cpp \
    KeyUidDMap.cpp \
    Uid.cpp \
    Key.cpp \
    Sortable.cpp \
    ocBase.cpp

HEADERS += \
#    AbstractString.h \
 #   BaseString.h \
    ../../include/Key \
    ../../include/KeyMap \
    AsciiChar.h \
    AsciiString.h \
    Error.h \
    KeyUidDMap.h \
    TypeDefs.h \
    Uid.h \
    Key.h \
    KeyMap.h \
    Sortable.h \
    ocBase.h \
    ocBase_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
