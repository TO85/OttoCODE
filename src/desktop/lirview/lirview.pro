QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

message(****************In ./src/desktop/lirview.pro)
include(../desktop.pri)
include(../../libs/useBase.pri)
#include(../../libs/useLog.pri)
include(../../libs/useType.pri)
include(../../libs/useCore.pri)
#include(../../libs/useGui.pri)
#include(../../libs/useWidgets.pri)
#include(../../libs/useExe.pri)
#include(../../libs/useImage.pri)
#include(../../libs/useColor.pri)
include(../../libs/useExe.pri)

SOURCES += \
    BaseTaskMenu.cpp \
    FileTaskMenu.cpp \
    MainWindow.cpp \
    main.cpp \

HEADERS += \
    BaseTaskMenu.h \
    FileTaskMenu.h \
    MainWindow.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
