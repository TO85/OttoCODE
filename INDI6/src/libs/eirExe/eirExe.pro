QT += widgets ### QAction

TEMPLATE = lib
DEFINES += EIREXE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

message(================In eirExe.pro)
include(../libs.pri)
include(../useType.pri)

SOURCES += \
    ActionManager.cpp \
    AppOptions.cpp \
    AppSettings.cpp \
    AppSupport.cpp \
    CommandLine.cpp \
    Configuration.cpp \
    Console.cpp \
    FeaturesManager.cpp \
    ImageSupport.cpp \
    PriorityKey.cpp \
    PriorityQueueInterface.cpp \
    PriorityTQueue.cpp \
    Settings.cpp \
    StatusMessage.cpp \
    eirExe.cpp \

HEADERS += \
    ActionManager.h \
    AppOptions.h \
    AppSettings.h \
    AppSupport.h \
    CommandLine.h \
    Configuration.h \
    Console.h \
    FeaturesManager.h \
    ImageSupport.h \
    PriorityKey.h \
    PriorityQueueInterface.h \
    PriorityTQueue.h \
    Settings.h \
    StatusMessage.h \
    SupporterInterface.h \
    eirExe_global.h \
    eirExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
