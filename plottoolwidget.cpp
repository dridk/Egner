#include "plottoolwidget.h"

PlotToolWidget::PlotToolWidget(QWidget *parent) :
    AbstractToolWidget(parent)
{

    mPlot = new QCustomPlot;
    setWindowTitle("Plot");

    mPlot->show();
    mPlot->addGraph();


}

PlotToolWidget::~PlotToolWidget()
{

}

void PlotToolWidget::started()
{
    mPlot->show();
    mPlot->addGraph();
    mStep = 0;
    mX.clear();
    mY.clear();
}

void PlotToolWidget::running(int killed)
{
    mX.append(mStep);
    mY.append(killed);
    mStep++;

}

void PlotToolWidget::finished()
{
     QPen pen;
     pen.setColor(QColor(0, 0, 255, 200));
     mPlot->graph()->setLineStyle(QCPGraph::lsLine);
     mPlot->graph()->setPen(pen);
     mPlot->graph()->setBrush(QBrush(QColor(255/4.0,160,50,150)));

    mPlot->graph()->setData(mX,mY);
    mPlot->graph()->rescaleAxes();
    //    mPlot->xAxis->setRange(0, mX.size());
//    mPlot->yAxis->setRange(0,simulator()->maxCount());

    mPlot->resize(600,400);

    mPlot->show();

}

