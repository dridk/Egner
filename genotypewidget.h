#ifndef GENOTYPEWIDGET_H
#define GENOTYPEWIDGET_H

#include <QWidget>
#include <QTableView>
#include "genotypeNetwork.h"
class GenotypeWidget : public QWidget
{
public:
    GenotypeWidget(const GenotypeNetwork& genotype,QWidget * parent=0);
    ~GenotypeWidget();

private:
    GenotypeNetwork mGenotype;
};

#endif // GENOTYPEWIDGET_H
