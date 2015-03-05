#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"
#include "entity.h"
#include "simulator.h"
#include <QDateTime>

#include "genotypewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


    Genotype g("1,2,3,4,5,6,7,8,9");



    //    MainWindow w;
    //    w.show();

    return a.exec();
}
