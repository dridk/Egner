#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T11:59:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Egner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    genotype.cpp \
    phenotype.cpp \
    entity.cpp \
    simulator.cpp

HEADERS  += mainwindow.h \
    genotype.h \
    phenotype.h \
    entity.h \
    simulator.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 
