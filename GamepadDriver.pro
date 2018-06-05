#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T21:39:53
#
#-------------------------------------------------

QT += core gui serialport
LIBS += -lKernel32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = GamepadDriver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    GamepadState.cpp \
    Communicator.cpp \
    EventHandler.cpp \
    MainWindow.cpp \
    reactions/JoystickReaction.cpp \
    main.cpp \
    reactions/MouseJoystickReaction.cpp \
    reactions/KeyboardJoystickReaction.cpp \
    CustomConfiguration.cpp \
    reactions/KeyboardKey.cpp \
    Configurations.cpp \
    PressEater.cpp

HEADERS += \
    Communicator.h \
    GamepadState.h \
    Constants.h \
    EventHandler.h \
    reactions/JoystickReaction.h \
    MainWindow.h \
    reactions/MouseJoystickReaction.h \
    reactions/KeyboardJoystickReaction.h \
    CustomConfiguration.h \
    reactions/KeyboardKey.h \
    Configurations.h \
    PressEater.h

FORMS += \
    CustomConfiguration.ui

DISTFILES += \
    .gitignore \
    README.md \
    diagram.qmodel
