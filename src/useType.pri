# file: {Lancelot}./src/libs/useType.pri

message(----------------In useType.pri)

windows:LIBS *= -locType1
linux:LIBS *= -locType

#message(LIBS = $$LIBS)

