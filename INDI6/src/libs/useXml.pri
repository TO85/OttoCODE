# file: {INDI6 repo}./src/libs/useXml.pri

message(----------------In useXml.pri)

windows:LIBS *= -leirXml6
linux:LIBS *= -leirXml

message(LIBS = $$LIBS)

