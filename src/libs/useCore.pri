# file: {OttoCODE}./src/libs/useCore.pri

message(----------------In useCore.pri)

windows:LIBS *= -locqCore1
linux:LIBS *= -locqCore
#linux:LIBS *= $$DESTDIR/libocqCore.so

#message(LIBS = $$LIBS)

