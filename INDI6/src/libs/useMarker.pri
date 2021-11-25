# file: {INDI6 repo}./src/libs/useMarker.pri

message(----------------In useMarker.pri)

windows:LIBS *= -lIfMarker6
linux:LIBS *= -lIfMarker

message(LIBS = $$LIBS)

