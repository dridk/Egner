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



      Phenotype p;



























    //    MainWindow w;
    //    w.show();

    return a.exec();
}
