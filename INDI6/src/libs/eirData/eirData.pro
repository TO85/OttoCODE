# QT -= gui ### QImage, &c
QT *= xml

TEMPLATE = lib
DEFINES += EIRDATA_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirData.pro)
include(../libs.pri)
PRECOMPILED_HEADER = ./eirData-Qt5-pch.h
include(../useType.pri)


SOURCES += \
    BaseVolatileSettings.cpp \
    CommandLineSettings.cpp \
    DataMap.cpp \
    DomVariantElement.cpp \
    DomVariantEncoding.cpp \
    SettingsSnapshot.cpp \
    eirData.cpp

HEADERS += \
    BaseVolatileSettings.h \
    CommandLineSettings.h \
    DataMap.h \
    DomVariantElement.h \
    DomVariantEncoding.h \
    SettingsSnapshot.h \
    eirData-Qt5-pch.h \
    eirData_global.h \
    eirData.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
