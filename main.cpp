#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"
#include <QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());
    QVector<int> genotype;
    genotype.append(0);
    genotype.append(0);
    genotype.append(2);

    genotype.append(4);
    genotype.append(1);
    genotype.append(7);

    genotype.append(5);
    genotype.append(0);
    genotype.append(4);


    Genotype g(genotype);
    Genotype g2;

    Genotype child = g + g2;

    qDebug()<<g.toString();

    qDebug()<<child.toString();



    //    MainWindow w;
//    w.show();

    return a.exec();
}
