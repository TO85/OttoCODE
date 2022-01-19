QT += widgets

TEMPLATE = lib
DEFINES += OCQWIDGETS_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    MenuManager.cpp \
    QQMainWindow.cpp \
    ocqWidgets.cpp

HEADERS += \
    MenuManager.h \
    QQMainWindow.h \
    ocqWidgets_global.h \
    ocqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
