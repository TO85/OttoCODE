QT += gui

TEMPLATE = lib
DEFINES += OCOPENCV_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
