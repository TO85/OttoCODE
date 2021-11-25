QT -= gui

TEMPLATE = lib
DEFINES += EIRXFR_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirXfr.pro)
include(../libs.pri)

SOURCES += \
    StartupDebug.cpp \
    eirXfr.cpp

HEADERS += \
    Debug.h \
    StartupDebug.h \
    eirXfr_global.h \
    eirXfr.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
