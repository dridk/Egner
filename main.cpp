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
Phenotype p ;

p.set(0,34);

qDebug()<<p.toNormalVector();

//    qDebug()<<e->phenotype().geneCount();

























    //    MainWindow w;
//    w.show();

    return a.exec();
}
