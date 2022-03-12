QT += gui \
    widgets

TEMPLATE = lib
DEFINES += OCIMAGE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)
include(../useGui.pri)

SOURCES += \
    FloatImage.cpp \
    FloatImagePlane.cpp \
    ImageFileDialog.cpp \
    ImageFileFormat.cpp \
    ImageFileFormatManager.cpp \
    ImageInfo.cpp \
    ImageMdiDocument.cpp \
    ImagePak.cpp \
    VideoFileFormat.cpp \
    ocImage.cpp

HEADERS += \
    ../../include/ImageFileDialog \
    ../../include/ImageFileFormat \
    ../../include/ImageInfo \
    ../../include/ImageMdiDocument \
    ../../include/ImagePak \
    ../../include/VideoFileFormat \
    FloatImage.h \
    FloatImagePlane.h \
    ImageFileDialog.h \
    ImageFileFormat.h \
    ImageFileFormatManager.h \
    ImageInfo.h \
    ImageMdiDocument.h \
    ImagePak.h \
    VideoFileFormat.h \
    ocImage_global.h \
    ocImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
