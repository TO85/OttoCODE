QT -= gui
QT *= network ## QHostInfo

TEMPLATE = lib
DEFINES += OCTYPE_LIBRARY


include(../libs.pri)
include(../useBase.pri)

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
    Null.cpp \
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
    ../../include/CRect \
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
    ../../include/Null \
    ../../include/Point \
    ../../include/ProcessId \
    ../../include/Rational \
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
    CRect.h \
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
    Null.h \
    Point.h \
    ProcessId.h \
    Rational.h \
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
