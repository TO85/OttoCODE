# file: {INDI6 repo}./src/libs/useExe.pri

message(----------------In useExe.pri)

windows:include(../useExe.pri)
linux:LIBS *= -leirExe

message(LIBS = $$LIBS)

