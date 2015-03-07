#include "simmainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotypeNetwork.h"
#include "phenotype.h"
#include "simulator.h"
#include <QDateTime>

#include "genotypewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


//    SimMainWindow mainwindow;

//    mainwindow.show();


    Simulator sim;

//    sim.init(400);

    sim.load("/tmp/sim_init.txt");



    sim.run(200);

//    sim.save("/tmp/sim_final.txt");






    //    MainWindow w;
    //    w.show();

    return a.exec();
}
