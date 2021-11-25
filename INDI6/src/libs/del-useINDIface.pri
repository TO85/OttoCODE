# file: {INDI6 repo}./src/libs/useINDIface.pri

message(----------------In useINDIface.pri)

windows:LIBS *= -lINDIface6
linux:LIBS *= -lINDIface

message(LIBS = $$LIBS)

