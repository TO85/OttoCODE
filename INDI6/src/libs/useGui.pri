# file: {INDI6 repo}./src/libs/useGui.pri

message(----------------In useGui.pri)

windows:LIBS *= -leirGui6
linux:LIBS *= -leirGui

message(LIBS = $$LIBS)

