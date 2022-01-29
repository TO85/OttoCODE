QT -= gui
QT *= network

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
    FunctionInfo.cpp \
    HostId.cpp \
    KeyUidDMap.cpp \
    Millisecond.cpp \
    NetworkId.cpp \
    ProcessId.cpp \
    Uid.cpp \
    Key.cpp \
    Sortable.cpp \
    ocBase.cpp

HEADERS += \
#    AbstractString.h \
 #   BaseString.h \
    ../../include/AsciiChar \
    ../../include/AsciiString \
    ../../include/FunctionInfo \
    ../../include/HostId \
    ../../include/Key \
    ../../include/KeyMap \
    ../../include/KeyUidDMap \
    ../../include/Millisecond \
    ../../include/NetworkId \
    ../../include/Sortable \
    ../../include/TypeDefs \
    ../../include/Uid \
    AsciiChar.h \
    AsciiString.h \
    Error.h \
    FunctionInfo.h \
    HostId.h \
    KeyUidDMap.h \
    Millisecond.h \
    NetworkId.h \
    ProcessId.h \
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
