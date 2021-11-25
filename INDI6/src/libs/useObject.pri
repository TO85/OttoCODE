# file: {INDI6 repo}./src/libs/useObject.pri

message(----------------In useObject.pri)

windows:LIBS *= -lIfObject6
linux:LIBS *= -lIfObject

message(LIBS = $$LIBS)

