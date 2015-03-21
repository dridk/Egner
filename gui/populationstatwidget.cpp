#include "populationstatwidget.h"
#include <QVBoxLayout>
PopulationStatWidget::PopulationStatWidget(Population * pop, QWidget *parent)
    : QWidget(parent)
{

    mPop = pop;
    mPlot = new QCustomPlot;

    QVBoxLayout * l = new QVBoxLayout;
    l->addWidget(mPlot);
    setLayout(l);


    mPlot->plotLayout()->clear();


    mPlot->setInteraction(QCP::iRangeZoom,true);
    mPlot->setInteraction(QCP::iRangeDrag,true);



}

PopulationStatWidget::~PopulationStatWidget()
{

}

void PopulationStatWidget::refresh()
{
    if (mPop->count() == 0)
        return;

    int geneCount = mPop->at(0).geneCount();

    mPlot->plotLayout()->clear();
    mPlot->clearGraphs();
    mPlot->clearPlottables();


    int min = mPop->minValue();
    int max = mPop->maxValue();


    for (int x=0; x< geneCount; ++x)
    {

        for (int y=0; y< geneCount; ++y)
        {



            QCPAxisRect * axisRect =  new QCPAxisRect(mPlot);
            mPlot->plotLayout()->addElement(y,x,axisRect);



            QCPBars *newGraph = new QCPBars(axisRect->axis(QCPAxis::atBottom),
                                                              axisRect->axis(QCPAxis::atLeft));



            QVector<double> datax;
            QVector<double> datay;

            QMap<double,double> mMap;

            int s = max - min;

            newGraph->setWidth(1);


            for (int i=0; i<mPop->count(); ++i)
            {
                double val = mPop->at(i).at(x,y);
                double key = int(val) % s;

               if (!mMap.contains(key))
                   mMap.insert(key, 1);
               else
                   mMap[key]++;


            }

            newGraph->setData(mMap.keys().toVector(), mMap.values().toVector());
            axisRect->axis(QCPAxis::atBottom)->setRange(-20,20);
            axisRect->axis(QCPAxis::atLeft)->setRange(-20,20);
            newGraph->rescaleAxes();


        }
    }


mPlot->replot();

}

