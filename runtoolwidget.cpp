#include "runtoolwidget.h"
#include <QProgressDialog>
RunToolWidget::RunToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{
    mIterationBox = new QSpinBox;
    mParentCountBox = new QSpinBox;
    mRunButton = new QPushButton("Run");
    mMutationBox= new QDoubleSpinBox;
    mPlotBox = new QCheckBox;
    mHistBox = new QCheckBox;
    mPlot  = new QCustomPlot();
    mMutationBox->setRange(0,1);
    mMutationBox->setSingleStep(0.01);
    setWindowTitle("Run");


    mProgressDialog = new QProgressDialog(this);
    mProgressDialog->setModal(true);
    mProgressDialog->setVisible(false);

    mIterationBox->setRange(0,10000);

    QFormLayout * l = new QFormLayout;

    l->addRow("Iteration", mIterationBox);
    l->addRow("Proba muta", mMutationBox);

    l->addRow("show Line plot", mPlotBox);
    l->addRow("show Histogram pot", mHistBox);


    QVBoxLayout * all = new QVBoxLayout;
    all->addLayout(l);
    all->addWidget(mRunButton);



    setLayout(all);

    connect(mRunButton,SIGNAL(clicked()),this,SLOT(run()));


}

RunToolWidget::~RunToolWidget()
{

}

void RunToolWidget::run()
{
    qDebug()<<"run...";
    int iteration = mIterationBox->value();

    mProgressDialog->setVisible(true);
    mProgressDialog->setLabelText("Computing...");
    mProgressDialog->setWindowTitle("loading");
    mProgressDialog->setRange(0,iteration);




    mX.clear();
    mY.clear();

    double proba = mMutationBox->value();

    for (int i = 0; i < iteration; i++) {

        int killed = population()->next(proba);

        qDebug()<<killed;
        mProgressDialog->setValue(i);


        mX.append(i);
        mY.append(killed);


    }

    mProgressDialog->setValue(iteration);

    if (mPlotBox->isChecked())
        showPlot();

    emit needRefresh();

}

void RunToolWidget::showPlot()
{

    mPlot->clearPlottables();
    mPlot->clearGraphs();

    mPlot->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    mPlot->graph()->setLineStyle(QCPGraph::LineStyle::lsLine);
    mPlot->graph()->setScatterStyle(QCPScatterStyle::ssCircle);

    mPlot->graph()->setPen(pen);
    mPlot->graph()->setBrush(QBrush(QColor(255/4.0,160,50,150)));

    mPlot->graph()->setData(mX,mY);
    mPlot->xAxis->rescale();
    mPlot->yAxis->setRange(0,population()->count());
    //    mPlot->xAxis->setRange(0, mX.size());
    ////    mPlot->yAxis->setRange(0,simulator()->maxCount());

    mPlot->setInteraction(QCP::iRangeZoom,true);
    mPlot->setInteraction(QCP::iRangeDrag,true);

    mPlot->resize(600,400);

    mPlot->showNormal();
    mPlot->replot();
}

