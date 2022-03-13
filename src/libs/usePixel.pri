# file: {OttoCODE}./src/libs/usePixel.pri

message(----------------In usePixel.pri)

windows:LIBS *= -locPixel1
linux:LIBS *= -locPixel
#linux:LIBS *= $$DESTDIR/libocqGui.so

message(LIBS = $$LIBS)

