QT -= gui

TEMPLATE = lib
DEFINES += OCLOG_LIBRARY


include(../libs.pri)
include(../useBase.pri)


SOURCES += \
    Log.cpp \
    LogChannel.cpp \
    LogItem.cpp \
    LogLevel.cpp \
    LogObject.cpp \
    LogPump.cpp \
    ocLog.cpp

HEADERS += \
    ../../include/Log \
    Log.h \
    LogChannel.h \
    LogItem.h \
    LogLevel.h \
    LogMacros.h \
    LogObject.h \
    LogPump.h \
    ocLog_global.h \
    ocLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
