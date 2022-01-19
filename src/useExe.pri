# file: {Lancelot}./src/libs/useExe.pri

message(----------------In useExe.pri)

#windows:include(../useExe.pri)
linux:LIBS *= -locExe

#message(LIBS = $$LIBS)

