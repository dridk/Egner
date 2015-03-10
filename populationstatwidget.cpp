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





    for (int x=0; x< geneCount; ++x)
    {

        for (int y=0; y< geneCount; ++y)
        {



            QCPAxisRect * axisRect =  new QCPAxisRect(mPlot);
            mPlot->plotLayout()->addElement(x,y,axisRect);



            QCPBars *newGraph = new QCPBars(axisRect->axis(QCPAxis::atBottom),
                                                              axisRect->axis(QCPAxis::atLeft));

            QVector<double> datax;
            QVector<double> datay;

            QMap<double, double> mMap;



            for (int i=0; i<mPop->count(); ++i)
            {
                double key = mPop->at(i).at(x,y);

                if (!mMap.contains(key))
                    mMap[key] = 0;
                else
                    mMap[key]++;

            }

            newGraph->setData(mMap.keys().toVector(), mMap.values().toVector());
            newGraph->rescaleAxes();



        }
    }




}

