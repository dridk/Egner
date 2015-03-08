#ifndef POPULATIONLISTWIDGET_H
#define POPULATIONLISTWIDGET_H

#include <QListWidget>
#include "population.h"
#include "genotypepixmap.h"

class PopulationListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit PopulationListWidget(Population * pop, QWidget *parent = 0);
    ~PopulationListWidget();


public slots:
    void populate();

private:
    Population * mPopulation;
};

#endif // POPULATIONLISTWIDGET_H
