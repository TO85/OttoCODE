# file: {OttoCODE}./src/libs/useImage.pri

message(----------------In useImage.pri)

windows:LIBS *= -locImage1
linux:LIBS *= -locImage

message(LIBS = $$LIBS)

