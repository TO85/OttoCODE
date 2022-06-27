# file: {Lancelot}./src/libs/useGui.pri

message(----------------In useGui.pri)

windows:LIBS *= -locqGui1
linux:LIBS *= -locqGui

#message(LIBS = $$LIBS)

