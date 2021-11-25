#QT -= gui ### QImage

TEMPLATE = lib
DEFINES += IFGEOMETRY_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In IfGeometry.pro)
include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)

SOURCES += \
    EyeGeometry.cpp \
    EyeLine.cpp \
    EyeLineF.cpp \
    EyeROI.cpp \
    FaceGeometry.cpp \
    FaceTypeRect.cpp \
    IfGeometry.cpp \
    del-EyeLineResults.cpp

HEADERS += \
    EyeGeometry.h \
    EyeLine.h \
    EyeLineF.h \
    EyeROI.h \
    FaceGeometry.h \
    FaceTypeRect.h \
    IfGeometry_global.h \
    IfGeometry.h \
    del-EyeLineResults.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
