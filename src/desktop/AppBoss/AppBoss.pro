QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../desktop.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useType.pri)
include(../../useCore.pri)
include(../../useGui.pri)
include(../../useWidgets.pri)
include(../../useExe.pri)

SOURCES += \
    BossMainWindow.cpp \
    EnvSubWin.cpp \
    EtcSubWin.cpp \
    main.cpp

HEADERS += \
    BossMainWindow.h \
    EnvSubWin.h \
    EtcSubWin.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
