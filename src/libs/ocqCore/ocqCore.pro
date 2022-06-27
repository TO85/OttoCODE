QT -= gui

TEMPLATE = lib
DEFINES += OCQCORE_LIBRARY


include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)

SOURCES += \
    ObjectHelper.cpp \
    QQDir.cpp \
    QQFile.cpp \
    QQFileInfo.cpp \
    QQFileInfoList.cpp \
    QQSize.cpp \
    QQString.cpp \
    QQStringList.cpp \
    ocqCore.cpp

HEADERS += \
    ../../include/ErrorObject \
    ../../include/ObjectHelper \
    ../../include/QQDir \
    ../../include/QQFile \
    ../../include/QQFileInfo \
    ../../include/QQFileInfoList \
    ../../include/QQSize \
    ../../include/QQString \
    ../../include/QQStringList \
    ObjectHelper.h \
    QQDir.h \
    QQFile.h \
    QQFileInfo.h \
    QQFileInfoList.h \
    QQSize.h \
    QQString.h \
    ocqCore_global.h \
    ocqCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
