# file: {OttoCODE}./src/libs/useExe.pri

message(----------------In useExe.pri)
#message(DESTDIR = $$DESTDIR)

windows:LIBS *= -locExe1
linux:LIBS *= -locExe
#linux:LIBS *= $$DESTDIR/libocExe.so
#message(LIBS = $$LIBS)

