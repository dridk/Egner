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

#include "Individu.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand(QDateTime::currentDateTime ().toTime_t ());


//    while (1==1){
//    Individu a("1.2665,-0.345691,0.682868,-0.303345,0.577478,-1.06389,0.827422,2.8062,1.34263,-0.651157,0.183126,1.88161,0.300111,0.516058,1.30157,0.779431,1.00345,-1.01964,1.15518,-0.0636308,-0.00342606,1.98418,-1.33104,0.610181,0.583461");

//    Individu b("1.58604,0.880351,0.851216,-0.544598,0.492866,0.544011,1.90105,-0.43493,-0.663491,0.925475,1.98207,1.1079,-1.12929,0.649922,-1.44565,0.10842,1.54414,-0.540724,0.0864465,0.469314,-0.123565,0.1733,1.11245,-0.17184,1.7157");


//    Individu c (a.getGenotype(), b.getGenotype());

//    if (!c.isViable())
//        qDebug()<<"non viable";

//    }




//    QString raw="0.946742,-0.253603,-0.258219,1.18882,-0.11427,1.01499,1.74608,-0.119702,-0.559387,-0.739383,-0.371364,-0.663116,-0.616488,1.4774,-0.0557501,1.32512,0.390309,2.29783,-1.23636,-0.404034,0.597291,2.49459,1.1807,-1.51585,0.255059";


   // GenotypeNetwork g("0,0,2,4,1,7,5,0,4");


//    qDebug()<<g.testViability(Phenotype("1,1,-1"));


   // qDebug()<<g.lastPhenotype(Phenotype("1,1,-1")).raw();

//    Individu i(raw);

//    GenotypeNetwork g(raw);

//    qDebug()<<i.isViable();
//    qDebug()<<g.testViability();




//    GenotypeNetwork g("1,2,-3,4,-5,6,7,8,9");

//    Phenotype p("1,2,3");

//    qDebug()<<g.testViability();

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
        w.show();
        w.resize(600,400);

    return app.exec();
}
