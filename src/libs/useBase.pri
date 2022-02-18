# file: {OttoCODE}./src/libs/useBase.pri

message(----------------In useBase.pri)
message(DESTDIR = $$DESTDIR)

windows:LIBS *= -locBase1
linux:LIBS *= -locBase
#linux:LIBS *= $$DESTDIR/libocBase.so
message(LIBS = $$LIBS)

