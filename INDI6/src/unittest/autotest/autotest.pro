QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

message(================In /home/dev/github/EIRC/INDI6/src/unittest/autotest/autotest.pro)

include(autotest.pri)

SOURCES += \
    testType/testType.cpp \
    testType/test_eirType_DualMap.cpp \
    testType/test_eirType_WeightedAverageF.cpp \
        tst_autotest.cpp \
        ../../libs/eirType/eirType.cpp \
        ../../libs/eirType/BasicName.cpp \
        ../../libs/eirType/Boolean.cpp \
        ../../libs/eirType/QQString.cpp \
        ../../libs/eirType/QQStringList.cpp \
        ../../libs/eirType/Success.cpp \
        ../../libs/eirType/WeightedAverageF.cpp \

HEADERS += \
        ../../libs/eirType/eirType.h \
        ../../libs/eirType/DualMap.h \
    testType/testType.h \
    testType/test_eirType_DualMap.h \
    testType/test_eirType_WeightedAverageF.h

DISTFILES += \
    testType/testType.icpp \
    testType/testType.ih

