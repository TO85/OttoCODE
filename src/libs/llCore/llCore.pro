QT -= gui

TEMPLATE = lib
DEFINES += LLCORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    Key.cpp \
    KeyMap.cpp \
    Sortable.cpp \
    llCore.cpp

HEADERS += \
    ../../include/Key \
    ../../include/KeyMap \
    Key.h \
    KeyMap.h \
    Sortable.h \
    llCore_global.h \
    llCore.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
