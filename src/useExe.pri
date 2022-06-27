# file: {Lancelot}./src/libs/useExe.pri

message(----------------In useExe.pri)

windows:LIBS *= -locExe1
linux:LIBS *= -locExe

#message(LIBS = $$LIBS)

