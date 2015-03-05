#ifndef ENTITY_H
#define ENTITY_H
#include "phenotype.h"
#include "genotype.h"
#include <QSet>
class Entity
{
public:
    Entity(int geneCount=3);
    Entity(const Genotype& g);
    Entity(const Genotype &g, Phenotype& p);
    ~Entity();

    Genotype &genotype();
    Phenotype &phenotype();


    bool isViable();
    int geneCount();


    static Entity *childFromParent(const QList<Entity*> parents);


    const QString &name();
    QString raw();




private:
    Genotype mGenotype;
    Phenotype mPhenotype;
    QString mName;
    QSet<QString> mHistory;
};

#endif // ENTITY_H
