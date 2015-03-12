#include "runtoolwidget.h"
#include <QProgressDialog>
#include <QColorDialog>
RunToolWidget::RunToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{
    mIterationBox = new QSpinBox;
    mParentCountBox = new QSpinBox;
    mRunButton = new QPushButton("Run");
    mMutationBox= new QDoubleSpinBox;
    mPlotBox = new QCheckBox;
    mHistBox = new QCheckBox;
    mColorButton = new QToolButton;
    mPlot  = new QCustomPlot();
    mClearGraph =  new QPushButton("Clear graph");
    mHistPlot = new QCustomPlot();
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
    l->addRow("Set Color", mColorButton);


    QVBoxLayout * all = new QVBoxLayout;
    all->addLayout(l);
    all->addWidget(mClearGraph);
    all->addWidget(mRunButton);



    setLayout(all);

    connect(mRunButton,SIGNAL(clicked()),this,SLOT(run()));
    connect(mClearGraph,SIGNAL(clicked()),this,SLOT(clearGraph()));
    connect(mColorButton,SIGNAL(clicked()),this,SLOT(getColor()));

    setColor(Qt::blue);


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

    mTotalKilled = 0;


    for (int i = 0; i < iteration; i++) {

        int killed = population()->next(proba);
        mTotalKilled += killed;

        qDebug()<<killed;
        mProgressDialog->setValue(i);


        mX.append(i);
        mY.append(killed);


    }

    mProgressDialog->setValue(iteration);

    if (mPlotBox->isChecked())
        showPlot();

    if (mHistBox->isChecked())
        showHist();

    emit needRefresh();

}

void RunToolWidget::showPlot()
{

    mPlot->addGraph();
    mPlot->graph()->setLineStyle(QCPGraph::LineStyle::lsLine);
    mPlot->graph()->setScatterStyle(QCPScatterStyle::ssCircle);



    QColor col = mCurrentColor;
    col.setAlpha(50);



    mPlot->graph()->setPen(QPen(mCurrentColor));
    mPlot->graph()->setBrush(QBrush(col));

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

void RunToolWidget::showHist()
{

    QCPBars *newGraph = new QCPBars(mHistPlot->xAxis, mHistPlot->yAxis);
    mHistPlot->addPlottable(newGraph);


    QVector<double> tx;
    QVector<double> ty;

    qDebug()<<mTotalKilled;

    tx.append(mHistPlot->plottableCount());
    ty.append(mTotalKilled);

    newGraph->setData(tx,ty);

//    tx.append(mHistPlot->plottableCount());
//    ty.append(mTotalKilled);

//    QPen pen;
//    pen.setColor(QColor(0, 0, 255, 200));

//    mHistPlot->graph()->setPen(pen);
//    mHistPlot->graph()->setBrush(QBrush(QColor(255/mPlot->graphCount(),160,50,150)));
//    mHistPlot->graph()->setData(tx, ty);


    QColor col = mCurrentColor;
    col.setAlpha(50);

    newGraph->setBrush(QBrush(col));
    newGraph->setPen(QPen(mCurrentColor));

    mHistPlot->setInteraction(QCP::iRangeZoom,true);
    mHistPlot->setInteraction(QCP::iRangeDrag,true);

    mHistPlot->resize(600,400);

//    newGraph->rescaleAxes();
    mHistPlot->showNormal();
    mHistPlot->replot();





}

void RunToolWidget::clearGraph()
{

    mPlot->clearPlottables();
    mHistPlot->clearPlottables();
    mPlot->clearGraphs();
    mHistPlot->clearPlottables();
    mPlot->replot();
    mHistPlot->replot();
}

void RunToolWidget::getColor()
{

    setColor(QColorDialog::getColor());



}

void RunToolWidget::setColor(const QColor &col)
{
    mCurrentColor = col;
    QPixmap pix(32,32);
    pix.fill(col);

    mColorButton->setIcon(QIcon(pix));

}

