# file: {INDI6 repo}./src/libs/useIfData.pri

message(----------------In useIfData.pri)

windows:LIBS *= -LIfData6
linux:LIBS *= -lIfData

message(LIBS = $$LIBS)

