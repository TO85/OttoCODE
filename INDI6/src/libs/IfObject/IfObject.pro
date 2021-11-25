#QT -= gui ### QImage

TEMPLATE = lib
DEFINES += IFOBJECT_LIBRARY

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


message(================In IfObject.pro)
include(../libs.pri)
include(../useXfr.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useData.pri)
include(../useGui.pri)
include(../useExe.pri)
include(../useOpenCV.pri)
include(../useGeometry.pri)

SOURCES += \
    FaceData.cpp \
    FinderCatalog.cpp \
    FrameData.cpp \
    GrouperMethods.cpp \
    NormalizedFaceImage.cpp \
    ObjectDetector.cpp \
    ObjectFinder.cpp \
    ObjectGrouper.cpp \
    ObjectRegion.cpp \
    ObjectResults.cpp \
    Quality.cpp \
    IfObject.cpp

HEADERS += \
    FaceData.h \
    FinderCatalog.h \
    FrameData.h \
    GrouperMethods.h \
    NormalizedFaceImage.h \
    ObjectDetector.h \
    ObjectFinder.h \
    ObjectGrouper.h \
    ObjectRegion.h \
    ObjectResults.h \
    Quality.h \
    IfObject_global.h \
    IfObject.h


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
