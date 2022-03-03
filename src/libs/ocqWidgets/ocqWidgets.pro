QT += widgets
QT *= gui

TEMPLATE = lib
DEFINES += OCQWIDGETS_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)
include(../useGui.pri)

SOURCES += \
    GridDialog.cpp \
    MdiGridWidget.cpp \
    MdiMainWindow.cpp \
    MdiSubWinWidget.cpp \
    QQMainWindow.cpp \
    QQMdiArea.cpp \
    ocqWidgets.cpp

HEADERS += \
    ../../include/GridDialog \
    ../../include/MdiGridWidget \
    ../../include/MdiMainWindow \
    ../../include/MdiSubWinWidget \
    ../../include/MenuManager \
    ../../include/QQMainWindow \
    ../../include/QQMdiArea \
    GridDialog.h \
    MdiGridWidget.h \
    MdiMainWindow.h \
    MdiSubWinWidget.h \
    QQMainWindow.h \
    QQMdiArea.h \
    ocqWidgets_global.h \
    ocqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
