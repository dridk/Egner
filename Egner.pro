#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T11:59:46
#
#-------------------------------------------------

QT       += widgets core gui  svg

QMAKE_CXXFLAGS += -std=c++11
CONFIG      += c++11 static
DEFINES     *= QT_USE_QSTRINGBUILDER


TARGET = Egner
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    genotype.cpp \
    phenotype.cpp \
    entity.cpp \
    simulator.cpp \
    abstractwatcher.cpp \
    zodiacgraph/baseedge.cpp \
    zodiacgraph/bezieredge.cpp \
    zodiacgraph/drawedge.cpp \
    zodiacgraph/edgearrow.cpp \
    zodiacgraph/edgegroup.cpp \
    zodiacgraph/edgegroupinterface.cpp \
    zodiacgraph/edgegrouppair.cpp \
    zodiacgraph/edgelabel.cpp \
    zodiacgraph/labeltextfactory.cpp \
    zodiacgraph/node.cpp \
    zodiacgraph/nodehandle.cpp \
    zodiacgraph/nodelabel.cpp \
    zodiacgraph/perimeter.cpp \
    zodiacgraph/plug.cpp \
    zodiacgraph/plugarranger.cpp \
    zodiacgraph/plugedge.cpp \
    zodiacgraph/plughandle.cpp \
    zodiacgraph/pluglabel.cpp \
    zodiacgraph/scene.cpp \
    zodiacgraph/scenehandle.cpp \
    zodiacgraph/straightdoubleedge.cpp \
    zodiacgraph/straightedge.cpp \
    zodiacgraph/view.cpp \
    genotypeview.cpp

HEADERS  += mainwindow.h \
    genotype.h \
    phenotype.h \
    entity.h \
    simulator.h \
    abstractwatcher.h \
    zodiacgraph/baseedge.h \
    zodiacgraph/bezieredge.h \
    zodiacgraph/drawedge.h \
    zodiacgraph/edgearrow.h \
    zodiacgraph/edgegroup.h \
    zodiacgraph/edgegroupinterface.h \
    zodiacgraph/edgegrouppair.h \
    zodiacgraph/edgelabel.h \
    zodiacgraph/labeltextfactory.h \
    zodiacgraph/node.h \
    zodiacgraph/nodehandle.h \
    zodiacgraph/nodelabel.h \
    zodiacgraph/perimeter.h \
    zodiacgraph/plug.h \
    zodiacgraph/plugarranger.h \
    zodiacgraph/plugedge.h \
    zodiacgraph/plughandle.h \
    zodiacgraph/pluglabel.h \
    zodiacgraph/scene.h \
    zodiacgraph/scenehandle.h \
    zodiacgraph/straightdoubleedge.h \
    zodiacgraph/straightedge.h \
    zodiacgraph/utils.h \
    zodiacgraph/view.h \
    genotypeview.h

FORMS    += mainwindow.ui

RESOURCES += res/icons.qrc

DISTFILES += \
    zodiacgraph/zodiacgraph.pri


