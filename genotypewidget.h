#ifndef GENOTYPEWIDGET_H
#define GENOTYPEWIDGET_H

#include <QWidget>
#include "genotype.h"
class GenotypeWidget : public QWidget
{
public:
    GenotypeWidget(const Genotype& genotype,QWidget * parent);
    ~GenotypeWidget();

private:
    Genotype mGenotype;
};

#endif // GENOTYPEWIDGET_H
