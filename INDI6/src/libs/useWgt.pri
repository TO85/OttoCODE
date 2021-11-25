# file: {INDI6 repo}./src/libs/useWgt.pri

message(----------------In useWgt.pri)

windows:LIBS *= -leirWgt6
linux:LIBS *= -leirWgt

message(LIBS = $$LIBS)

