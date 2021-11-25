# file: {INDI6 repo}./src/libs/useXfr.pri

message(----------------In useXfr.pri)

windows:LIBS *= -leirXfr6
linux:LIBS *= -leirXfr

message(LIBS = $$LIBS)

