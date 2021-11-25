# @file Ib6Dash.pro Qt6 qmake Project file for INDIbase Six Dashboard
QT       += core gui sql svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(++++++++++++++++In IfSearch6.pro)

include(../desk.pri)
include(../../../libs/useXfr.pri)
include(../../../libs/useBase.pri)
include(../../../libs/useType.pri)
include(../../../libs/useData.pri)
include(../../../libs/useXml.pri)
include(../../../libs/useExe.pri)
include(../../../libs/useGui.pri)
include(../../../libs/useWgt.pri)
include(../../../libs/useGeometry.pri)

SOURCES += \
    DatabaseManager.cpp \
    MainStack.cpp \
    ServerPage.cpp \
    StatusPage.cpp \
    main.cpp \
    MainWindow.cpp \

HEADERS += \
    DatabaseManager.h \
    MainStack.h \
    MainWindow.h \
    ServerPage.h \
    StatusPage.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc/logos.qrc
