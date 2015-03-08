#ifndef ABSTRACTTOOLWIDGET_H
#define ABSTRACTTOOLWIDGET_H

#include <QWidget>
#include "population.h"
class AbstractToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractToolWidget(QWidget *parent = 0);
    ~AbstractToolWidget();
    void setSimulator(Population * sim);
    Population *simulator();



protected slots:
    virtual void started() {}
    virtual void running(int killed) {}
    virtual void finished() {}

private:
    Population * mSim;

};

#endif // ABSTRACTTOOLWIDGET_H
