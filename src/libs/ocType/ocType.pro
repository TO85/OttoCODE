QT -= gui
QT *= network ## QHostInfo

TEMPLATE = lib
DEFINES += OCTYPE_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    AsciiChar.cpp \
    AsciiString.cpp \
    BaseString.cpp \
    CommaString.cpp \
    Error.cpp \
    FourCC.cpp \
    FunctionInfo.cpp \
    HostId.cpp \
    JsonMap.cpp \
    JsonVariable.cpp \
    MimeType.cpp \
    MimeTypeManager.cpp \
    NetworkId.cpp \
    ProcessId.cpp \
    Rect.cpp \
    SortableMap.cpp \
    StringTree.cpp \
    Variable.cpp \
    VariableList.cpp \
    VariableMap.cpp \
    VariablePak.cpp \
    ocType.cpp

HEADERS += \
    ../../include/AsciiChar \
    ../../include/AsciiString \
    ../../include/CommaString \
    ../../include/DualMap \
    ../../include/HostId \
    ../../include/JsonMap \
    ../../include/JsonVariable \
    ../../include/Matrix2D \
    ../../include/MimeType \
    ../../include/MimeTypeManager \
    ../../include/NetworkId \
    ../../include/ProcessId \
    ../../include/SortableMap \
    ../../include/String \
    ../../include/Variable \
    ../../include/VariableList \
    ../../include/VariableMap \
    ../../include/VariablePak \
    AsciiChar.h \
    AsciiString.h \
    BaseString.h \
    CommaString.h \
    DualMap.h \
    Error.h \
    FourCC.h \
    FunctionInfo.h \
    HostId.h \
    JsonMap.h \
    JsonVariable.h \
    Matrix2D.h \
    MimeType.h \
    MimeTypeManager.h \
    NetworkId.h \
    ProcessId.h \
    Rect.h \
    SortableMap.h \
    StringTree.h \
    Variable.h \
    VariableList.h \
    VariableMap.h \
    VariablePak.h \
    ocType_global.h \
    ocType.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
