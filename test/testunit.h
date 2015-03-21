#ifndef TESTUNIT_H
#define TESTUNIT_H

#include <QObject>
#include <QtTest/QTest>

#include "phenotype.h"
#include "genotypeNetwork.h"
#include "population.h"

class TestUnit : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testGenotypeCreation();
    void testPhenotypeCreation();
    void testGenotypeCrossPhenotype();
    void testGenotypePlusGenotype();
    void testViability();
    void testInitialisation();
    void cleanupTestCase();


private:
    GenotypeNetwork mGenotype;
    Phenotype mPhenotype;
};

#endif // TESTUNIT_H
