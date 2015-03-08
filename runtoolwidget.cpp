#include "runtoolwidget.h"
#include <QProgressDialog>
RunToolWidget::RunToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{
    mIterationBox = new QSpinBox;
    mParentCountBox = new QSpinBox;
    mRunButton = new QPushButton("Run");
    mBar = new QProgressBar;
    setWindowTitle("Run");

    mIterationBox->setRange(0,10000);

    QFormLayout * l = new QFormLayout;

    l->addRow("Iteration", mIterationBox);

    QVBoxLayout * all = new QVBoxLayout;
    all->addLayout(l);
    all->addWidget(mBar);
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
    mBar->setRange(0,iteration);



//  population()->disableAll(2);

    mX.clear();
    mY.clear();

    for (int i = 0; i < iteration; i++) {

        int killed = population()->next();

        qDebug()<<killed;
        mBar->setValue(i);

        mX.append(i);
        mY.append(killed);

    }

    mBar->setValue(iteration);

    qDebug()<<mY;
    showPlot();

    emit needRefresh();

}

void RunToolWidget::showPlot()
{

    QCustomPlot * plot = new QCustomPlot;
    plot->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    plot->graph()->setLineStyle(QCPGraph::lsLine);
    plot->graph()->setPen(pen);
    plot->graph()->setBrush(QBrush(QColor(255/4.0,160,50,150)));

    plot->graph()->setData(mX,mY);
    plot->graph()->rescaleAxes();
    //    mPlot->xAxis->setRange(0, mX.size());
    ////    mPlot->yAxis->setRange(0,simulator()->maxCount());

    plot->resize(600,400);

    plot->show();
}

