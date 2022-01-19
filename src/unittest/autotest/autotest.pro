QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

#LIBS *= -ltplBase

SOURCES += \
        tst_autotest.cpp \
        ../../libs/tplBase/tplBase.cpp \

HEADERS += \
        ../../libs/tplBase/tplBase.h \

