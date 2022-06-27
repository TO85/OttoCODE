QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(======== in Excelsior.pro)
include(../desktop.pri)
include(../../libs/useBase.pri)
include(../../libs/useType.pri)
include(../../libs/useCore.pri)
include(../../libs/useGui.pri)
include(../../libs/useWidgets.pri)
include(../../libs/useOpenCV.pri)
include(../../libs/useColor.pri)
include(../../libs/usePixel.pri)
include(../../libs/useImage.pri)
include(../../libs/useExe.pri)

#message(INCLUDEPATH = $${INCLUDEPATH})
#message(LIBS = $${LIBS})

SOURCES += \
#    PixcelsiorFrameGridMdiSub.cpp \
#    PixcelsiorFrameWidget.cpp \
    PixcelsiorDocumentGrid.cpp \
    PixcelsiorImageDocument.cpp \
    PixcelsiorImageGridBlock.cpp \
    PixcelsiorImageGridItem.cpp \
    PixcelsiorMain.cpp \
    main.cpp

HEADERS += \
#    PixcelsiorFrameGridMdiSub.h \
#    PixcelsiorFrameWidget.h \
    PixcelsiorDocumentGrid.h \
    PixcelsiorImageDocument.h \
    PixcelsiorImageGridBlock.h \
    PixcelsiorImageGridItem.h \
    PixcelsiorMain.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
