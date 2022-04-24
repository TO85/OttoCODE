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
    GraphicsLayer.cpp \
    GridDialog.cpp \
    MdiDocument.cpp \
    MdiGridSubWin.cpp \
    MdiMainWindow.cpp \
    QQGridLayout.cpp \
    QQMainWindow.cpp \
    QQMdiArea.cpp \
    ocqWidgets.cpp

HEADERS += \
    ../../include/GridDialog \
    ../../include/MdiGridSubWin \
    ../../include/MdiMainWindow \
    ../../include/MenuManager \
    ../../include/QQGridLayout \
    ../../include/QQMainWindow \
    ../../include/QQMdiArea \
    GraphicsLayer.h \
    GridDialog.h \
    MdiDocument.h \
    MdiGridSubWin.h \
    MdiMainWindow.h \
    QQGridLayout.h \
    QQMainWindow.h \
    QQMdiArea.h \
    ocqWidgets_global.h \
    ocqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
