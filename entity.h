#ifndef ENTITY_H
#define ENTITY_H
#include "phenotype.h"
#include "genotype.h"
#include <QSet>
class Entity
{
public:
    Entity(int geneCount=3);
    ~Entity();

    Genotype &genotype();
    Phenotype &phenotype();
    void killLater();
    bool needKill();
    bool run();

    const QString &name();




private:
    Genotype mGenotype;
    Phenotype mPhenotype;
    QString mName;
    bool mKill;
    QSet<QString> mHistory;
};

#endif // ENTITY_H
