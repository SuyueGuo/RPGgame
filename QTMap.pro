#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T13:10:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTMap
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    mw1.cpp \
    icon.cpp \
    rpgobj.cpp \
    world.cpp \
    monster.cpp \
    character.cpp \
    player.cpp \
    magician.cpp \
    warrior.cpp

HEADERS  += \
    mw1.h \
    icon.h \
    rpgobj.h \
    world.h \
    monster.h \
    character.h \
    player.h \
    magician.h \
    warrior.h

FORMS    += \
    mw1.ui

DISTFILES += \
    images/background.png \
    images/background2.png \
    images/knight1a.png \
    images/boss1a.png \
    images/death.jpg \
    death.jpg \
    images/boss1a.png
