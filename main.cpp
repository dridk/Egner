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
    QApplication app(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());



//    Population pop;



//        pop.init(10,0,1,6);

//        GenotypeNetwork a = GenotypeNetwork("0,0,2,4,1,7,5,0,4");
//        GenotypeNetwork b = GenotypeNetwork("0,1,0,3,1,0,5,8,4");



//        Phenotype r = Phenotype("1,1,1") * a;

//        qDebug()<<r.raw();

    //    TestUnit * test = new TestUnit();
    //    QTest::qExec(test);
    //    return 0;



    //    GenotypeNetwork gn("1,2,3,4,5,6,7,8,9");
    //    GenotypeNetwork gb("11,22,33,44,55,66,77,88,99");

    //    GenotypeNetwork c = gn.add(gb);

    //    qDebug()<<c.raw();


        SimMainWindow w;
        w.showMaximized();

    return app.exec();
}
