# file: {INDI6 repo}./src/libs/useBase.pri

message(----------------In useBase.pri)

windows:LIBS *= -leirBase6
linux:LIBS *= -leirBase

message(LIBS = $$LIBS)

