#======================================================================

QT += core opengl widgets gui

CONFIG += staticlib qt
TEMPLATE = lib

PROJNAME = GLViewer

# SDK, APP, MOD
INSTALLTYPE = SDK

unix:INCLUDEPATH += /usr/include/eigen3

#LIBS +=

#======================================================================

include(RobotSDK.pri)
