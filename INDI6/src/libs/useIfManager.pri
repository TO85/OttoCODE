# file: {INDI6 repo}./src/libs/useIfManager.pri

message(----------------In useIfManager.pri)

windows:LIBS *= -lIfManager6
linux:LIBS *= -lIfManager

message(LIBS = $$LIBS)

