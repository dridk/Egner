#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"
#include "entity.h"
#include "simulator.h"
#include <QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


    Genotype g;
    g.fromRaw("0,0,2,4,1,7,5,0,4");

    Genotype g2;
    g2.fromRaw("0,1,0,3,1,0,5,8,4");

    Phenotype p;
    p.fromRaw("1,1,1");


    Genotype c = g + g2;

    qDebug()<<g.raw();
    qDebug()<<g2.raw();

    qDebug()<<c.raw();




//     Simulator sim;

//     sim.init(0,1,10);

//     qDebug()<<sim.count();





























    //    MainWindow w;
    //    w.show();

    return a.exec();
}
