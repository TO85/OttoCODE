QT -= gui

TEMPLATE = lib
DEFINES += OCMATH_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Angle.cpp \
    Degrees.cpp \
    Orthorhombic3d.cpp \
    Parallelogram2d.cpp \
    Point2d.cpp \
    Point2dMD.cpp \
    Point3d.cpp \
    Radians.cpp \
    Rect2d.cpp \
    Rhombus2d.cpp \
    Size2d.cpp \
    Size3d.cpp \
    ocMath.cpp

HEADERS += \
    Angle.h \
    Degrees.h \
    Orthorhombic3d.h \
    Parallelogram2d.h \
    Point2d.h \
    Point2dMD.h \
    Point3d.h \
    Radians.h \
    Rect2d.h \
    Rhombus2d.h \
    Size2d.h \
    Size3d.h \
    TScalar.h \
    TUnitFloat.h \
    ocMath_global.h \
    ocMath.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
