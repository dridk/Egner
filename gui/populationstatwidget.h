#ifndef POPULATIONSTATWIDGET_H
#define POPULATIONSTATWIDGET_H
#include <QWidget>
#include "qcustomplot.h"
#include "population.h"
class PopulationStatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PopulationStatWidget(Population * pop, QWidget *parent = 0);
    ~PopulationStatWidget();

public slots:
    void refresh();

private:
    QCustomPlot * mPlot ;
    Population * mPop;
};

#endif // POPULATIONSTATWIDGET_H
