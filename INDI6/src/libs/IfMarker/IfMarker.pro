#QT -= gui

TEMPLATE = lib
DEFINES += IFMARKER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useData.pri)
include(../useGeometry.pri)
include(../useObject.pri)

SOURCES += \
    AbstractImageQueue.cpp \
    DirectMarkedFrameMarker.cpp \
    EncoderInterface.cpp \
    IfMarker.cpp \
    ImageQueueManager.cpp \
    MarkedImageEntry.cpp \
    MarkerInterface.cpp \
    MarkerType.cpp

HEADERS += \
    AbstractImageQueue.h \
    DirectMarkedFrameMarker.h \
    EncoderInterface.h \
    IfMarker_global.h \
    IfMarker.h \
    ImageQueueManager.h \
    MarkedImageEntry.h \
    MarkerInterface.h \
    MarkerType.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
