QT += gui

TEMPLATE = lib
DEFINES += OCCOLOR_LIBRARY


include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)

SOURCES += \
    Color.cpp \
    CompoundColor.cpp \
    RgbColorTable.cpp \
    ocColor.cpp

HEADERS += \
    ../../include/Color \
    ../../include/CompoundColor \
    Color.h \
    CompoundColor.h \
    RgbColorTable.h \
    ocColor_global.h \
    ocColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
