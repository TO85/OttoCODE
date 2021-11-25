# QT -= gui ### QImage

TEMPLATE = lib
DEFINES += EIROPENCV_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirOpenCV.pro)
include(../libs.pri)
#include(../../opencv.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useOpenCV.pri)

SOURCES += \
    cvCascade.cpp \
    cvException.cpp \
    cvHighGui.cpp \
    cvMat.cpp \
    cvMatQImage.cpp \
    cvMatType.cpp \
    cvPoint.cpp \
    cvQRect.cpp \
    cvQSize.cpp \
    cvQString.cpp \
    cvQStringList.cpp \
    cvRect.cpp \
    cvSize.cpp \
    cvString.cpp \
    cvStringList.cpp \
    eirOpenCV.cpp

HEADERS += \
    cvCascade.h \
    cvException.h \
    cvHighGui.h \
    cvMat.h \
    cvMatQImage.h \
    cvMatType.h \
    cvPoint.h \
    cvQRect.h \
    cvQSize.h \
    cvQString.h \
    cvQStringList.h \
    cvRect.h \
    cvSize.h \
    cvString.h \
    cvStringList.h \
    eirOpenCV_global.h \
    eirOpenCV.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
