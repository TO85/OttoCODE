QT += gui

TEMPLATE = lib
DEFINES += OCOPENCV_LIBRARY


include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)

SOURCES += \
    cvMat.cpp \
    ocOpenCV.cpp

HEADERS += \
    cvMat.h \
    ocOpenCV_global.h \
    ocOpenCV.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
