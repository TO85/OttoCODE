# file: {Lancelot}./src/libs/useWidgets.pri

message(----------------In useWidgets.pri)

windows:LIBS *= -locqWidgets1
linux:LIBS *= -locqWidgets

#message(LIBS = $$LIBS)

