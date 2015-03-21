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
    core/genotypeNetwork.cpp \
    core/phenotype.cpp \
    core/population.cpp \
    gui/abstracttoolwidget.cpp \
    gui/abstractwatcher.cpp \
    gui/genotypedialog.cpp \
    gui/genotypepixmap.cpp \
    gui/genotypewidget.cpp \
    gui/infotoolwidget.cpp \
    gui/inittoolwidget.cpp \
    gui/knockouttoolwidget.cpp \
    gui/listtoolwidget.cpp \
    gui/mutationtoolwidget.cpp \
    gui/plottoolwidget.cpp \
    gui/populationlistwidget.cpp \
    gui/populationstatwidget.cpp \
    gui/propertylistwidget.cpp \
    gui/propertywidgetcontainer.cpp \
    gui/qcustomplot.cpp \
    gui/runtoolwidget.cpp \
    gui/simmainwindow.cpp \
    test/testunit.cpp


HEADERS  += \
    core/genotypeNetwork.h \
    core/phenotype.h \
    core/population.h \
    gui/abstracttoolwidget.h \
    gui/abstractwatcher.h \
    gui/genotypedialog.h \
    gui/genotypepixmap.h \
    gui/genotypewidget.h \
    gui/infotoolwidget.h \
    gui/inittoolwidget.h \
    gui/knockouttoolwidget.h \
    gui/listtoolwidget.h \
    gui/mutationtoolwidget.h \
    gui/plottoolwidget.h \
    gui/populationlistwidget.h \
    gui/populationstatwidget.h \
    gui/propertylistwidget.h \
    gui/propertywidgetcontainer.h \
    gui/qcustomplot.h \
    gui/runtoolwidget.h \
    gui/simmainwindow.h \
    test/testunit.h

INCLUDEPATH += gui core test

FORMS    +=

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    gfx/gfx.qrc

