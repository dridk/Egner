#ifndef GENOTYPEWIDGET_H
#define GENOTYPEWIDGET_H

#include <QWidget>
#include <QTableView>
#include "genotype.h"
class GenotypeWidget : public QWidget
{
public:
    GenotypeWidget(const Genotype& genotype,QWidget * parent=0);
    ~GenotypeWidget();

private:
    Genotype mGenotype;
};

#endif // GENOTYPEWIDGET_H
