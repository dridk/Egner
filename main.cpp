#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotype.h"
#include "phenotype.h"
#include "entity.h"
#include "simulator.h"
#include <QDateTime>

#include "genotypeview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


    Genotype g;
    g.fromRaw("1,2,3,4,5,6,7,8,9");

    GenotypeView * widget = new GenotypeView(g);

    widget->show();

    //    MainWindow w;
    //    w.show();

    return a.exec();
}
