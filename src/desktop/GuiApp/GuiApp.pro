QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../desktop.pri)

SOURCES += \
    main.cpp \
    MainWidget.cpp

HEADERS += \
    MainWidget.h

FORMS += \
    MainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
