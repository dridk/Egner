#include "abstracttoolwidget.h"

AbstractToolWidget::AbstractToolWidget(QWidget *parent)
    : QWidget(parent)
{

}

AbstractToolWidget::~AbstractToolWidget()
{

}

void AbstractToolWidget::setPopulation(Population *sim)
{
    mSim = sim;
}

Population *AbstractToolWidget::population()
{
    return mSim;
}

