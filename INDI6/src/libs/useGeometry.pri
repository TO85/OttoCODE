# file: {INDI6 repo}./src/libs/useGeometry.pri

message(----------------In useGeometry.pri)

windows:LIBS *= -lIfGeometry6
linux:LIBS *= -lIfGeometry

message(LIBS = $$LIBS)

