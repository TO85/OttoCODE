# file: {INDI6 repo}./src/libs/useResource.pri

message(----------------In useResource.pri)

windows:LIBS *= -lIf1Resource6
linux:LIBS *= -lIf1Resource

message(LIBS = $$LIBS)

