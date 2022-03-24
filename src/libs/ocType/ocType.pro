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
    Boolean.cpp \
    CommaString.cpp \
    Error.cpp \
    FourCC.cpp \
    FunctionInfo.cpp \
    HostId.cpp \
    JsonMap.cpp \
    JsonVariable.cpp \
    Line.cpp \
    MimeType.cpp \
    MimeTypeManager.cpp \
    NetworkId.cpp \
    Point.cpp \
    ProcessId.cpp \
    Rational.cpp \
    Rect.cpp \
    Size.cpp \
    SortableMap.cpp \
    StringTree.cpp \
    Success.cpp \
    Variable.cpp \
    VariableList.cpp \
    VariableMap.cpp \
    VariablePak.cpp \
    internal/FunctionInfoData.cpp \
    ocType.cpp

HEADERS += \
    ../../include/AsciiChar \
    ../../include/AsciiString \
    ../../include/Boolean \
    ../../include/CommaString \
    ../../include/DualMap \
    ../../include/HostId \
    ../../include/JsonMap \
    ../../include/JsonVariable \
    ../../include/Line \
    ../../include/Matrix2D \
    ../../include/MimeType \
    ../../include/MimeTypeManager \
    ../../include/NetworkId \
    ../../include/Point \
    ../../include/ProcessId \
    ../../include/Rational \
    ../../include/Rect \
    ../../include/Size \
    ../../include/SortableMap \
    ../../include/Success \
    ../../include/Variable \
    ../../include/VariableList \
    ../../include/VariableMap \
    ../../include/VariablePak \
    AsciiChar.h \
    AsciiString.h \
    BaseString.h \
    Boolean.h \
    CommaString.h \
    DualMap.h \
    FourCC.h \
    FunctionInfo.h \
    HostId.h \
    JsonMap.h \
    JsonVariable.h \
    Line.h \
    Matrix2D.h \
    MimeType.h \
    MimeTypeManager.h \
    NetworkId.h \
    Point.h \
    ProcessId.h \
    Rational.h \
    Rect.h \
    Size.h \
    SortableMap.h \
    StringTree.h \
    Success.h \
    Variable.h \
    VariableList.h \
    VariableMap.h \
    VariablePak.h \
    internal/FunctionInfoData.h \
    ocType_global.h \
    ocType.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
