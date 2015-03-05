#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"
#include "entity.h"
#include "simulator.h"
#include <QDateTime>
#include "qcustomplot.h"
#include "genotypewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


    Simulator sim;

    sim.init(300,0, 1, 10);

    int iter=50;
    sim.run(iter);

    qDebug()<<sim.deads().count();

    QCustomPlot * plot = new QCustomPlot;

    plot->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    plot->graph()->setLineStyle(QCPGraph::lsLine);
    plot->graph()->setPen(pen);
    plot->graph()->setBrush(QBrush(QColor(255/4.0,160,50,150)));

    QVector<double> x(iter);
    for (int i=0; i<iter; ++i)
        x[i] = i;



    QVector<double> y = sim.deads().toVector();

    plot->graph()->setData(x,y);
    plot->yAxis->setRange(0,5000);
    plot->xAxis->setRange(0,iter);



    plot->resize(600,400);
    plot->show();

            //    MainWindow w;
            //    w.show();

            return a.exec();
}
