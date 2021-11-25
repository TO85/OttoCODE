QT -= gui

TEMPLATE = lib
DEFINES += TOLOGCORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LogItem.cpp \
    LogLevel.cpp \
    LogUid.cpp \
    log.cpp \
    toLogCore.cpp

HEADERS += \
    LogItem.h \
    LogLevel.h \
    LogUid.h \
    log.h \
    toLogCore_global.h \
    toLogCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
