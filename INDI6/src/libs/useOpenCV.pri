# file: {INDI6 repo}./src/libs/useOpenCV.pri

message(----------------In useOpenCV.pri)

message(EIRC_QTCVINCLUDEPATH = $${EIRC_QTCVINCLUDEPATH})
message(EIRC_QTCVFILENAMEVER = $${EIRC_QTCVFILENAMEVER})
message(EIRC_QTCVLIBPATH = $${EIRC_QTCVLIBPATH})

INCLUDEPATH *= $${EIRC_QTCVINCLUDEPATH}
LIBS *= -L$${EIRC_QTCVLIBPATH}

windows {
    !contains(DEFINES, EIROPENCV_LIBRARY) LIBS *= -leirOpenCV
    CONFIG(release, debug|release):LIBS *= -lopencv_world$$(EIRC_QTCVFILENAMEVER)
    CONFIG(debug, debug|release):LIBS *= -lopencv_world$$(EIRC_QTCVFILENAMEVER)d
}
linux {
    !contains(DEFINES, EIROPENCV_LIBRARY) LIBS *= -leirOpenCV
    LIBS *= -lopencv_core
    LIBS *= -lopencv_objdetect
    LIBS *= -lopencv_highgui
    LIBS *= -lopencv_imgcodecs
}

message(INCLUDEPATH = $${INCLUDEPATH})
message(LIBS = $$LIBS)

