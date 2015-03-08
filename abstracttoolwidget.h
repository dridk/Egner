#ifndef ABSTRACTTOOLWIDGET_H
#define ABSTRACTTOOLWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include "population.h"
class AbstractToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractToolWidget(QWidget *parent = 0);
    ~AbstractToolWidget();
    void setPopulation(Population * sim);
    Population *population();


signals:
    void needRefresh();

public slots:
    virtual void refresh(){}


private:
    Population * mSim;

};

#endif // ABSTRACTTOOLWIDGET_H
