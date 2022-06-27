# file: {Lancelot}./src/libs/useLog.pri

message(----------------In useLog.pri)

windows:LIBS *= -locLog1
linux:LIBS *= -locLog

#message(LIBS = $$LIBS)

