# file: {Lancelot}./src/libs/useCore.pri

message(----------------In useCore.pri)

windows:LIBS *= -locqCore1
linux:LIBS *= -locqCore

#message(LIBS = $$LIBS)

