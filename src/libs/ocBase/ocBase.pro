QT -= gui
QT *= network

TEMPLATE = lib
DEFINES += OCBASE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
#    AbstractString.cpp \
 #   BaseString.cpp \
    AsciiChar.cpp \
    AsciiString.cpp \
    Error.cpp \
    FourCC.cpp \
    FunctionInfo.cpp \
    HostId.cpp \
    Ident.cpp \
    JsonMap.cpp \
    JsonVariable.cpp \
    KeyList.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyUidDMap.cpp \
    Millisecond.cpp \
    MimeType.cpp \
    MimeTypeManager.cpp \
    NetworkId.cpp \
    ProcessId.cpp \
    Rect.cpp \
    SortableMap.cpp \
    String.cpp \
    StringList.cpp \
    StringTree.cpp \
    Uid.cpp \
    Key.cpp \
    Sortable.cpp \
    Variable.cpp \
    VariableList.cpp \
    VariableMap.cpp \
    VariablePak.cpp \
    ocBase.cpp

HEADERS += \
    ../../include/AsciiChar \
    ../../include/AsciiString \
    ../../include/Enumeration \
    ../../include/FunctionInfo \
    ../../include/HostId \
    ../../include/JsonMap \
    ../../include/JsonVariable \
    ../../include/Key \
    ../../include/KeyList \
    ../../include/KeySeg \
    ../../include/KeyMap \
    ../../include/KeyUidDMap \
    ../../include/Matrix2D \
    ../../include/Millisecond \
    ../../include/MimeType \
    ../../include/MimeTypeManager \
    ../../include/NetworkId \
    ../../include/ProcessId \
    ../../include/Sortable \
    ../../include/SortableMap \
    ../../include/String \
    ../../include/StringList \
    ../../include/TypeDefs \
    ../../include/Uid \
    ../../include/Variable \
    ../../include/VariableList \
    ../../include/VariableMap \
    ../../include/VariablePak \
    AsciiChar.h \
    AsciiString.h \
    Error.h \
    FourCC.h \
    FunctionInfo.h \
    HostId.h \
    Ident.h \
    JsonMap.h \
    JsonVariable.h \
    KeyList.h \
    KeySeg.h \
    KeySegList.h \
    KeyUidDMap.h \
    Matrix2D.h \
    Millisecond.h \
    MimeType.h \
    MimeTypeManager.h \
    NetworkId.h \
    ProcessId.h \
    Rect.h \
    SortableMap.h \
    String.h \
    StringList.h \
    StringTree.h \
    TypeDefs.h \
    Uid.h \
    Key.h \
    KeyMap.h \
    Sortable.h \
    Variable.h \
    VariableList.h \
    VariableMap.h \
    VariablePak.h \
    ocBase.h \
    ocBase_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../data/ocBase/Contact1.json
