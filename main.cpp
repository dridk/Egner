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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());




    GenotypeNetwork g1("-7,-1,9,4,-7,14,-3,-7,13");
    GenotypeNetwork g2("2,21,4,10,8,-1,-3,-7,13");

    GenotypeNetwork r  = g1 + g2;

    qDebug()<<r.raw();


//    TestUnit * test = new TestUnit();
//    QTest::qExec(test);
//    return 0;



//    GenotypeNetwork gn("1,2,3,4,5,6,7,8,9");
//    GenotypeNetwork gb("11,22,33,44,55,66,77,88,99");

//    GenotypeNetwork c = gn.add(gb);

//    qDebug()<<c.raw();


    SimMainWindow w;
    w.showMaximized();

    return a.exec();
}
