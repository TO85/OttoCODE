# file: {INDI6 repo}./src/src.pri

message(----------------In ./src/src.pri)
message(QMAKESPEC = $${QMAKESPEC})

# DEFINES *= EIRC_NO_INDI1DATA

include(hosts.pri)
include(version.pri)
include(build.pri)
include(dest.pri)
include(paths.pri)

message(OURDEST = $$OURDEST)
message(LIBS = $$LIBS)
message(EIRC_BASEDESTDIR = $${EIRC_BASEDESTDIR})
message(EIRC_QT5INCLUDEBASE = $${EIRC_QT5INCLUDEBASE})
message(EIRC_QTCVINCLUDEPATH = $${EIRC_QTCVINCLUDEPATH})
message(EIRC_QTCVFILENAMEVER = $${EIRC_QTCVFILENAMEVER})
message(EIRC_QTCVLIBPATH = $${EIRC_QTCVLIBPATH})
