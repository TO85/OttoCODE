DEFINES *= DETECTOR_SCALE=4.0
DEFINES *= USE_OCV4
CONFIG += debug_and_release

#win32-g++: TODO
linux-g++: INCLUDEPATH *= /usr/local/include/opencv4
LIBS *= -L/usr/local/lib
LIBS *= -lopencv_core
LIBS *= -lopencv_imgproc
LIBS *= -lopencv_objdetect
#LIBS += /usr/local/lib/libopencv_core.so.4.5.5
#LIBS += /usr/local/lib/libopencv_imgproc.so.4.5.5
#LIBS += /usr/local/lib/libopencv_objdetect.so.4.5.5

#CONFIG(debug, debug|release) {
#    win32-g++:  INCLUDEPATH *= /lang/OpenCV-2.2.0/dbg-w32/include
#    win32-g++:  LIBS *= -L/lang/OpenCV-2.2.0/dbg-w32/lib
#    win32-g++:  LIBS *= -lopencv_objdetect220d.dll -lopencv_core220d.dll
#    linux-g++:	INCLUDEPATH *= /usr/local/include/opencv4
#    linux-g++:	LIBS += -L/usr/local/lib
#    linux-g++:	LIBS += -lopencv_objdetect
#} else {
#    win32-g++:  INCLUDEPATH *= /lang/OpenCV-2.2.0/bin-w32/include
#    win32-g++:  LIBS *= -L/lang/OpenCV-2.2.0/bin-w32/lib
#    win32-g++:	LIBS *= -lopencv_objdetect220.dll -lopencv_core220.dll
#    linux-g++:	INCLUDEPATH *= /usr/local/include/opencv4
#    linux-g++:	LIBS += -L/usr/local/lib
#    linux-g++:	LIBS += -lopencv_objdetect
#}
