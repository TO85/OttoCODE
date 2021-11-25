# file: {INDI6 repo}./src/hosts/eagle.pri

message(----------------In ./src/hosts/eagle.pri)
message(QMAKESPEC = $${QMAKESPEC})

# EIRC_QMAKE_HOST=eagle
message(EIRC_QMAKE_HOST eq $$(EIRC_QMAKE_HOST))
EIRC_HOST = $$(EIRC_QMAKE_HOST) # Convert system environment variable to qmake internal variable
contains(EIRC_HOST, eagle) {
    message("Building on eagle!")
    EIRC_BASEDESTDIR = /home/dev/INDIface/bin
    EIRC_QT5INCLUDEBASE = /opt/qt5/5.15.2/gcc_64/include
    EIRC_QTCVINCLUDEPATH = /usr/local/include/opencv4
    EIRC_QTCVFILENAMEVER = 4.5.3
    EIRC_QTCVLIBPATH = /usr/local/lib
}


#QMAKE_CXXFLAGS *= -j5

message(EIRC_BASEDESTDIR = $${EIRC_BASEDESTDIR})
message(EIRC_QT5INCLUDEBASE = $${EIRC_QT5INCLUDEBASE})
message(EIRC_QTCVINCLUDEPATH = $${EIRC_QTCVINCLUDEPATH})
message(EIRC_QTCVFILENAMEVER = $${EIRC_QTCVFILENAMEVER})
message(EIRC_QTCVLIBPATH = $${EIRC_QTCVLIBPATH})
