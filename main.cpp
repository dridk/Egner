#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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

    QVector<int> phenotype;
    phenotype.append(1);
    phenotype.append(1);
    phenotype.append(-1);

    Phenotype p(phenotype);

    qDebug()<<g.toString();
    qDebug()<<p.toString();



//    qDebug()<<g.toString();
//    qDebug()<<p.toString();

   Phenotype n = p * g;

   qDebug()<<n.toString();


    //    MainWindow w;
//    w.show();

    return a.exec();
}
