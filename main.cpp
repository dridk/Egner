#include "simmainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotypeNetwork.h"
#include "phenotype.h"
#include "population.h"
#include <QDateTime>
#include <QSplashScreen>
#include <QDebug>
#include "genotypewidget.h"
#include "testunit.h"
#include "populationlistwidget.h"
#include <QTextStream>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());

    Population pop;
    pop.init(200,0,1,3);
    pop.save("/tmp/xp1data.xp");

    QFile file("xp1.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    for (int j=0; j<50; ++j) {

        pop.load("/tmp/xp1data.xp");

        qDebug()<<j;
        pop.run(2000);
        stream<<pop[0].raw()<<"\n";

    }

     file.close();

qDebug()<<"end";

    //    SimMainWindow w;
    //    w.show();
    //    w.resize(600,400);

    return app.exec();
}
