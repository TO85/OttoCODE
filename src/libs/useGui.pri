# file: {OttoCODE}./src/libs/useGui.pri

message(----------------In useGui.pri)

windows:LIBS *= -locqGui1
#linux:LIBS *= -locqGui
linux:LIBS *= $$DESTDIR/libocqGui.so

message(LIBS = $$LIBS)

