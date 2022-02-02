QT -= gui

TEMPLATE = lib
DEFINES += OCLOG_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)


SOURCES += \
    Log.cpp \
    LogItem.cpp \
    LogLevel.cpp \
    LogObject.cpp \
    ocLog.cpp

HEADERS += \
    Log.h \
    LogItem.h \
    LogLevel.h \
    LogObject.h \
    ocLog_global.h \
    ocLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
