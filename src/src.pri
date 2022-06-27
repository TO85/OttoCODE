# {OttoCODE}./src/src.pri

message(----------------In ./src/src.pri)
#message(QMAKESPEC = $${QMAKESPEC})

OTTOCODE_BASEBINDIR = /tmp/buildQt/bin
include(hosts.pri)
include(version.pri)
include(build.pri)
include(dest.pri)
include(paths.pri)

CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

#message(OURDEST = $$OURDEST)
#message(LIBS = $$LIBS)
#message(OC_BASEDESTDIR = $${OC_BASEDESTDIR})
