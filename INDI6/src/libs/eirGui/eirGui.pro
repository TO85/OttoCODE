# QT -= gui Obviously!

TEMPLATE = lib
DEFINES += EIRGUI_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirGui.pro)
include(../libs.pri)
PRECOMPILED_HEADER = ./eirGui-Qt5-pch.h
include(../useType.pri)


SOURCES += \
    ColorWheel.cpp \
    Document.cpp \
    Hue.cpp \
    ImageObject.cpp \
    ImageSizeMap.cpp \
    QQBitmap.cpp \
    QQColor.cpp \
    QQIcon.cpp \
    QQImage.cpp \
    QQPixmap.cpp \
    QQTransform.cpp \
    eirGui.cpp

HEADERS += \
    ColorWheel.h \
    Document.h \
    Hue.h \
    ImageObject.h \
    ImageSizeMap.h \
    QQBitmap.h \
    QQColor.h \
    QQIcon.h \
    QQImage.h \
    QQPixmap.h \
    QQTransform.h \
    eirGui-Qt5-pch.h \
    eirGui_global.h \
    eirGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
