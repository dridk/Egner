#include "testunit.h"

void TestUnit::initTestCase()
{

}

void TestUnit::testGenotypeCreation()
{
    for (int i=2; i<20; ++i)
    {
        int geneCount = i*i;

        QStringList list;
        for (int j=0; j<geneCount; ++j)
        {
            int v = j;
            list.append(QString::number(v));
        }

        GenotypeNetwork g(list.join(","));
        qDebug()<<"GeneCount "<<geneCount;
        QVERIFY2(g.geneCount() == i, "Genotype cannot be created");
        QVERIFY(g.at(0,0) == 0);
        QVERIFY(g.at(i-1,i-1) == geneCount-1);
    }
}

void TestUnit::testPhenotypeCreation()
{
    Phenotype p("-1,1,-1,1,1");

    QVERIFY(p.geneCount() == 5);
    QVERIFY(p.at(0) == -1);
    QVERIFY(p.at(4) == 1);


}

void TestUnit::testGenotypeCrossPhenotype()
{

    GenotypeNetwork g("0,0,2,4,1,7,5,0,4");

    Phenotype i1("1,1,-1");
    Phenotype i2("1,1,1");


    Phenotype p1 = i1 * g;
    QVERIFY(p1.raw() == "-1,-1,1");

    Phenotype p2 = i2 * g;
    QVERIFY(p2.raw() == "1,1,1");

}

void TestUnit::testGenotypePlusGenotype()
{

    GenotypeNetwork g1("0,0,2,4,1,7,5,0,4");
    GenotypeNetwork g2("0,1,0,3,1,0,5,8,4");

    GenotypeNetwork c = g1 + g2;

    // A faire..



}

void TestUnit::testViability()
{

    GenotypeNetwork g1("0,0,2,4,1,7,5,0,4");
    Phenotype i1("1,1,-1");
    Phenotype i2("1,1,1");

    QVERIFY(g1.testViability(i1) == false);
    QVERIFY(g1.testViability(i2) == true);

}

void TestUnit::testInitialisation()
{

    Population sim;
    sim.init(300);

    QVERIFY(sim.count() == 300);

    for (int i=0; i<sim.count(); ++i)
    {
        QVERIFY(sim.at(i).testViability() == true);

    }



}


void TestUnit::cleanupTestCase()
{

}
