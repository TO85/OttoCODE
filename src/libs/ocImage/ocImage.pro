QT += gui \
    widgets

TEMPLATE = lib
DEFINES += OCIMAGE_LIBRARY


include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useColor.pri)
include(../usePixel.pri)

SOURCES += \
    BaseColorTable.cpp \
    BaseImage.cpp \
    BaseImageObject.cpp \
    BaseImagePlane.cpp \
    ColorImage.cpp \
    GreyImage.cpp \
    GreyImagePlane.cpp \
    ImageViewWidget.cpp \
    ocImage.cpp \
    ocImage.cpp

HEADERS += \
    AbstractImageProcessInterface.h \
    BaseColorTable.h \
    BaseImage.h \
    BaseImageObject.h \
    BaseImagePlane.h \
    ColorImage.h \
    GreyImage.h \
    GreyImagePlane.h \
    ImageViewWidget.h \
    ocImage_global.h \
    ocImage.h \
    typedefs.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
