#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T11:59:46
#
#-------------------------------------------------

QT       += core gui testlib printsupport
QMAKE_CXXFLAGS += -std=c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Egner
TEMPLATE = app


SOURCES += main.cpp\
    phenotype.cpp \
    abstractwatcher.cpp \
    genotypewidget.cpp \
    genotypeNetwork.cpp \
    simmainwindow.cpp \
    abstracttoolwidget.cpp \
    inittoolwidget.cpp \
    listtoolwidget.cpp \
    plottoolwidget.cpp \
    qcustomplot.cpp \
    testunit.cpp \
    population.cpp \
    genotypepixmap.cpp \
    populationlistwidget.cpp

HEADERS  += \
    phenotype.h \
    abstractwatcher.h \
    genotypewidget.h \
    genotypeNetwork.h \
    simmainwindow.h \
    abstracttoolwidget.h \
    inittoolwidget.h \
    listtoolwidget.h \
    plottoolwidget.h \
    qcustomplot.h \
    testunit.h \
    population.h \
    genotypepixmap.h \
    populationlistwidget.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

