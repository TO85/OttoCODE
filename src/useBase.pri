# file: {Lancelot}./src/libs/useBase.pri

message(----------------In useBase.pri)

windows:LIBS *= -locBase1
linux:LIBS *= -locBase

#message(LIBS = $$LIBS)

