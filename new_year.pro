#-------------------------------------------------
#
# Project created by QtCreator 2016-12-17T13:56:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new_year
TEMPLATE = app
#LIBS += -L /usr/lib/ \
  #      -lX11 \
   #     -lX11-xcb \

LIBS += /usr/lib/libxcb-screensaver.so
LIBS += /usr/lib/libX11.so
LIBS += /usr/lib/totem/plugins/screensaver/libscreensaver.so



SOURCES += main.cpp\
    wgt.cpp \   
    sneg.cpp \
    derevo.cpp \
    wind.cpp \
    abstractwidget.cpp


HEADERS  += \
    wgt.h \
    sneg.h \
    derevo.h \
    wind.h \
    abstractwidget.h


DISTFILES +=

RESOURCES += \
    res.qrc
