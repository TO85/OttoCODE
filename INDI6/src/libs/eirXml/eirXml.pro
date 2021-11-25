QT -= gui
QT *= xml

TEMPLATE = lib
DEFINES += EIRXML_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
PRECOMPILED_HEADER = ./eirXml-Qt5-pch.h
include(../useType.pri)

SOURCES += \
    DomFile.cpp \
    DomFileManager.cpp \
    DomStatus.cpp \
    ElementAttributeMap.cpp \
    QQDomDocument.cpp \
    QQDomElement.cpp \
    QQDomNode.cpp \
    eirXml.cpp

HEADERS += \
    DomFile.h \
#    DomResult.h \
    DomFileManager.h \
    DomStatus.h \
    ElementAttributeMap.h \
    QQDomDocument.h \
    QQDomElement.h \
    QQDomNode.h \
    eirXml-Qt5-pch.h \
    eirXml_global.h \
    eirXml.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
