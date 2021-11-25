#QT -= gui
QT *= xml

CONFIG += c++17 console
CONFIG -= app_bundle

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


message(++++++++++++++++In IfSearch6.pro)

include(../cons.pri)
include(../../../libs/useXfr.pri)
include(../../../libs/useBase.pri)
include(../../../libs/useType.pri)
include(../../../libs/useData.pri)
include(../../../libs/useXml.pri)
include(../../../libs/useExe.pri)
include(../../../libs/useGui.pri)
include(../../../libs/useOpenCV.pri)
include(../../../libs/useGeometry.pri)
include(../../../libs/useObject.pri)
include(../../../libs/useMarker.pri)
include(../../../libs/useIfData.pri)
include(../../../libs/useIfManager.pri)

SOURCES += \
    IfS6Console.cpp \
    main.cpp \

HEADERS += \
    ../../../../common.h \
    ../../../version.h \
    IfS6Console.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    MiniIssues.md \

