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
#    del-GraphicsLayer.cpp \
    QQGridLayout.cpp \
    QQMainWindow.cpp \
    QQMdiArea.cpp \
#    del-GridDialog.cpp \
#    del-MdiDocument.cpp \
#    del-MdiGridSubWin.cpp \
#    del-MdiMainWindow.cpp \
    ocqWidgets.cpp

HEADERS += \
#    ../../include/GridDialog \
#    ../../include/MdiGridSubWin \
#    ../../include/MdiMainWindow \
#    ../../include/MenuManager \
    ../../include/QQGridLayout \
    ../../include/QQMainWindow \
    ../../include/QQMdiArea \
#    del-GraphicsLayer.h \
    QQGridLayout.h \
    QQMainWindow.h \
    QQMdiArea.h \
#    del-GridDialog.h \
#    del-MdiDocument.h \
#    del-MdiGridSubWin.h \
#    del-MdiMainWindow.h \
    ocqWidgets_global.h \
    ocqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
