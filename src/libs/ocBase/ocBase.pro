QT -= gui
QT *= network

TEMPLATE = lib
DEFINES += OCBASE_LIBRARY


include(../libs.pri)

SOURCES += \
    Ident.cpp \
    Index.cpp \
    Key.cpp \
    KeyList.cpp \
    KeyMap.h \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyUidDMap.cpp \
    Millisecond.cpp \
    Sortable.cpp \
    Uid.cpp \
    ocBase.cpp \

HEADERS += \
    ../../include/Ident \
    ../../include/Index \
    ../../include/Key \
    ../../include/KeyList \
    ../../include/KeyMap \
    ../../include/KeySeg \
    ../../include/KeySegList \
    ../../include/KeySegList \
    ../../include/KeyUidDMap \
    ../../include/Millisecond \
    ../../include/Sortable \
    ../../include/Sortable \
    ../../include/Uid \
    ../../version.h \
    AbstractProcessMapInterface.h \
    AbstractProcessVarInterface.h \
    Ident.h \
    Index.h \
    Key.h \
    KeyList.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyUidDMap.h \
    Millisecond.h \
    Sortable.h \
    TypeDefs.h \
    Uid.h \
    ocBase.h \
    ocBase_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../../../../home/toor/.config/Qt/mytypes.py \
    ../../../data/ocBase/Contact1.json
