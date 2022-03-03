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
    ImageData.cpp \
    ImageFileDialog.cpp \
    ImageFileFormat.cpp \
    ImageFileFormatManager.cpp \
    ImageInfo.cpp \
    ImageViewWidget.cpp \
    VideoFileFormat.cpp \
    ocImage.cpp

HEADERS += \
    ../../include/ImageData \
    ../../include/ImageFileDialog \
    ../../include/ImageFileFormat \
    ../../include/ImageViewWidget \
    ImageData.h \
    ImageFileDialog.h \
    ImageFileFormat.h \
    ImageFileFormatManager.h \
    ImageInfo.h \
    ImageViewWidget.h \
    VideoFileFormat.h \
    ocImage_global.h \
    ocImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
