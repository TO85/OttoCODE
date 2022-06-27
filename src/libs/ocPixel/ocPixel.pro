QT -= gui

TEMPLATE = lib
DEFINES += OCPIXEL_LIBRARY


include(../libs.pri)
include(../useBase.pri)
include(../useGui.pri)
include(../useColor.pri)

SOURCES += \
    Pixel.cpp \
    ocPixel.cpp

HEADERS += \
    ../../include/Pixel \
    Pixel.h \
    ocPixel_global.h \
    ocPixel.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
