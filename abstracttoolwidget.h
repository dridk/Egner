#ifndef ABSTRACTTOOLWIDGET_H
#define ABSTRACTTOOLWIDGET_H

#include <QWidget>
#include "simulator.h"
class AbstractToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractToolWidget(QWidget *parent = 0);
    ~AbstractToolWidget();
    void setSimulator(Simulator * sim);
    Simulator *simulator();



protected slots:
    virtual void started() {}
    virtual void running(int killed) {}
    virtual void finished() {}

private:
    Simulator * mSim;

};

#endif // ABSTRACTTOOLWIDGET_H
