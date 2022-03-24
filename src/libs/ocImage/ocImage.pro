QT += gui \
    widgets

TEMPLATE = lib
DEFINES += OCIMAGE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)
include(../useType.pri)
include(../useGui.pri)
include(../useColor.pri)
include(../usePixel.pri)

SOURCES += \
    BaseImageGraphicsWidget.cpp \
    ColorFloatQImage.cpp \
    ColorQImage.cpp \
    FloatImage.cpp \
    FloatImagePlane.cpp \
    Frame.cpp \
    FrameGraphicsWidget.cpp \
    Image.cpp \
    ImageFileDialog.cpp \
    ImageFileFormat.cpp \
    ImageFileFormatManager.cpp \
    ImageInfo.cpp \
    ImageMdiDocument.cpp \
    ImagePak.cpp \
    TrollImageGeneratorBuiltin.cpp \
    VideoFileFormat.cpp \
    ocImage.cpp

HEADERS += \
    ../../include/FloatImage \
    ../../include/FloatImagePlane \
    ../../include/FrameGraphicsWidget \
    ../../include/Image \
    ../../include/ImageFileDialog \
    ../../include/ImageFileFormat \
    ../../include/ImageInfo \
    ../../include/ImageMdiDocument \
    ../../include/ImagePak \
    ../../include/VideoFileFormat \
    BaseImageGraphicsWidget.h \
    ColorFloatQImage.h \
    ColorQImage.h \
    FloatImage.h \
    FloatImagePlane.h \
    Frame.h \
    FrameGraphicsWidget.h \
    Image.h \
    ImageFileDialog.h \
    ImageFileFormat.h \
    ImageFileFormatManager.h \
    ImageGeneratorInterface.h \
    ImageInfo.h \
    ImageMdiDocument.h \
    ImagePak.h \
    TrollImageGeneratorBuiltin.h \
    VideoFileFormat.h \
    ocImage_global.h \
    ocImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
