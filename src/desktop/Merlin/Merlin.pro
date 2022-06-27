QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../desktop.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useType.pri)
include(../../useCore.pri)
include(../../useGui.pri)
include(../../useWidgets.pri)
include(../../useExe.pri)

SOURCES += \
    Actions.cpp \
    FrameImage.cpp \
    FrameWindow.cpp \
    PixmapWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Actions.h \
    FrameImage.h \
    FrameWindow.h \
    MainWindow.h \
    PixmapWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
