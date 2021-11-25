# file: {INDI6 repo}./src/libs/useData.pri

message(----------------In useData.pri)

windows:include(../useData.pri)
linux:LIBS *= -leirData

message(LIBS = $$LIBS)

