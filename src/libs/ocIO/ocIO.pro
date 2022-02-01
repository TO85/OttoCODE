#QT -= gui

TEMPLATE = lib
DEFINES += OCIO_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)

SOURCES += \
    DirectoryInfo.cpp \
    DirectoryTreeEntry.cpp \
    FileInfo.cpp \
    FileSystemObject.cpp \
    FileSystemTree.cpp \
    FileTreeEntry.cpp \
    ocIO.cpp

HEADERS += \
    ../../include/DirectoryInfo \
    ../../include/DirectoryTreeEntry \
    ../../include/FileInfo \
    ../../include/FileSystemObject \
    ../../include/FileSystemTree \
    ../../include/FileTreeEntry \
    DirectoryInfo.h \
    DirectoryTreeEntry.h \
    FileInfo.h \
    FileSystemObject.h \
    FileSystemTree.h \
    FileTreeEntry.h \
    ocIO_global.h \
    ocIO.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
