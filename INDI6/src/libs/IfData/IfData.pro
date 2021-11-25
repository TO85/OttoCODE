# file: {INDI6 repo}./src/libs/IfData/IfData.pro

QT += gui

TEMPLATE = lib
DEFINES += IFDATA_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


message(================In IfObject.pro)
include(../libs.pri)
include(../useXfr.pri)
include(../useBase.pri)
include(../useType.pri)
#include(../useData.pri)
include(../useGui.pri)

SOURCES += \
    AbstractResource.cpp \
    IfData.cpp \
    NormalEyeLine.cpp \
    ResourceAttributes.cpp \
    ResourceBaseData.cpp \
    ResourceBitMask.cpp \
    ResourceFloatVector.cpp \
    ResourceImages.cpp \
    ResourceManager.cpp \
    ResourceType.cpp \
#    del-ResourceData.cpp \
 #   del-ResourceElements.cpp \
  #  del-ResourceLoader.cpp \
 \   # del-ResourceName.cpp
    ResourceValues.cpp

HEADERS += \
    AbstractResource.h \
    IfData_global.h \
    IfData.h \
    NormalEyeLine.h \
    ResourceAttributes.h \
    ResourceBaseData.h \
    ResourceBitMask.h \
    ResourceFloatVector.h \
    ResourceImages.h \
    ResourceManager.h \
    ResourceType.h \
#    del-ResourceData.h \
 #   del-ResourceElements.h \
  #  del-ResourceElementsInterface.h \
   # del-ResourceLoader.h \
 \    #del-ResourceName.h
    ResourceValues.h



# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../resources/data/Face1/BitMask.xml \
    ../../resources/data/Face1/Face1.xml \
    ../../resources/data/Face1/FaceLayers.xml \
    ../../resources/data/Face1/MeanFace.xml \
    ../../resources/data/Face1/WeightMask.xml
