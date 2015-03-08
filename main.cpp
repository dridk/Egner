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




    SimMainWindow w;
    w.show();

    return a.exec();
}
