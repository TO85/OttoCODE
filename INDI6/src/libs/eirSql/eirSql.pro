QT -= gui

TEMPLATE = lib
DEFINES += EIRSQL_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirSql.pro)
include(../libs.pri)
include(../useType.pri)

SOURCES += \
    SqlManager.cpp \
    eirSql.cpp

HEADERS += \
    SqlManager.h \
    eirSql_global.h \
    eirSql.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
