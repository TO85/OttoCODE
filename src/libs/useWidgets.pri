# file: {OttoCODE}./src/libs/useWidgets.pri

message(----------------In useWidgets.pri)

windows:LIBS *= -locqWidgets1
#linux:LIBS *= -locqWidgets
linux:LIBS *= $$DESTDIR/libocqWidgets.so

message(LIBS = $$LIBS)

