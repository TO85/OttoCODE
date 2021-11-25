QT *= gui
QT *= widgets

TEMPLATE = lib
DEFINES += EIRWGT_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirWgt.pro)
include(../libs.pri)
include(../useType.pri)
#include(../useGui.pri)

SOURCES += \
    BaseStackedLayoutPage.cpp \
    IconGrid.cpp \
    QQGridLayout.cpp \
 QQStackedLayout.cpp \
    eirWgt.cpp \

HEADERS += \
    BaseStackedLayoutPage.h \
    IconGrid.h \
    QQGridLayout.h \
 QQStackedLayout.h \
    eirWgt_global.h \
    eirWgt.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

