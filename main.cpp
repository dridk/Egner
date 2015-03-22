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


    SimMainWindow w;
    w.show();
    w.resize(600,400);

    return app.exec();
}
