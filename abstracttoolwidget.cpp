#include "abstracttoolwidget.h"

AbstractToolWidget::AbstractToolWidget(QWidget *parent) : QWidget(parent)
{

}

AbstractToolWidget::~AbstractToolWidget()
{

}

void AbstractToolWidget::setSimulator(Simulator *sim)
{
    mSim = sim;

    connect(mSim, SIGNAL(started()),this,SLOT(started()));
    connect(mSim, SIGNAL(running(int)),this,SLOT(running(int)));
    connect(mSim, SIGNAL(finished()),this,SLOT(finished()));

}

Simulator *AbstractToolWidget::simulator()
{
    return mSim;
}

