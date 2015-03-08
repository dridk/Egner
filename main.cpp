#include "simmainwindow.h"
#include <QApplication>
#include <QDebug>
#include "genotypeNetwork.h"
#include "phenotype.h"
#include "population.h"
#include <QDateTime>
#include "genotypewidget.h"
#include "testunit.h"
#include "populationlistwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());



//    TestUnit * test = new TestUnit();
//    QTest::qExec(test);
//    return 0;


    GenotypeNetwork g1("0,0,2,4,1,7,5,0,4");




    Population pop;
    pop.init(400,0,1,5);

    pop.disableAll(2);

  pop.run(200);

    PopulationListWidget * w = new PopulationListWidget(&pop);


    w->populate();
    w->show();






    //    MainWindow w;
    //    w.show();

    return a.exec();
}
