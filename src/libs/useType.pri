# file: {OttoCODE}./src/libs/useType.pri

message(----------------In useType.pri)
message(DESTDIR = $$DESTDIR)

windows:LIBS *= -locType1
linux:LIBS *= -locType
message(LIBS = $$LIBS)

