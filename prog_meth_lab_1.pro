TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += \
    main.cpp \
    program.cpp \
    test/test.cpp

HEADERS += \
    program.h \
    test/test.h
