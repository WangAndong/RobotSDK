#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T17:14:33
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConfigProject
TEMPLATE = app


SOURCES += \
    configproject.cpp \
    main.cpp

HEADERS  += \
    configproject.h

FORMS    += \
    configproject.ui

unix{
    DESTDIR = ../../../Build/Tools

    target.path = $$(HOME)/SDK/RobotSDK/Tools
    INSTALLS += target
}

win32{
    DESTDIR = ../../../Build/Tools
}
