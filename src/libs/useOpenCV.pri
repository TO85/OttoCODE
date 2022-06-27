# file: {OttoCODE}./src/libs/useOpenCV.pri

message(----------------In useOpenCV.pri)
#message(DESTDIR = $$DESTDIR)

windows:LIBS *= -locOpenCV1
linux:LIBS *= -locOpenCV
#linux:LIBS *= $$DESTDIR/libocOpenCV.so
#message(LIBS = $$LIBS)

