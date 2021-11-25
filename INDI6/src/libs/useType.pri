# file: {INDI6 repo}./src/libs/useType.pri

message(----------------In useType.pri)

windows:LIBS *= -leirType6
linux:LIBS *= -leirType

message(LIBS = $$LIBS)

