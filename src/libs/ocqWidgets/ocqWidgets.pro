QT += widgets
QT *= gui

TEMPLATE = lib
DEFINES += OCQWIDGETS_LIBRARY

message(================In libs.pri)
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
    QQMdiSubWindow.cpp \
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
    ../../include/QQMdiSubWindow \
    QQGridLayout.h \
    QQMainWindow.h \
    QQMdiArea.h \
#    del-GridDialog.h \
#    del-MdiDocument.h \
#    del-MdiGridSubWin.h \
#    del-MdiMainWindow.h \
    QQMdiSubWindow.h \
    ocqWidgets_global.h \
    ocqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
