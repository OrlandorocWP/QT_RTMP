#-------------------------------------------------
#
# Project created by QtCreator 2023-10-09T11:22:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WP
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
LIBS += -L/path/to/libvlc/library -lvlc

