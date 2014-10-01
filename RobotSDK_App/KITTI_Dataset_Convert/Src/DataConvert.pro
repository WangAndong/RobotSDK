#======================================================================

QT += core xml widgets gui

CONFIG += qt
TEMPLATE = app

PROJNAME = DataConvert

# SDK, APP, MOD
INSTALLTYPE = APP

unix:INCLUDEPATH += /usr/include/eigen3

#======================================================================

include(RobotSDK.pri)
