#include "entity.h"

Entity::Entity(int geneCount)
{

 mGenotype  = Genotype(QVector<int>(geneCount*geneCount,0));
 mPhenotype = Phenotype(QVector<int>(geneCount,0));
}

Entity::~Entity()
{

}

Genotype &Entity::genotype()
{
    return mGenotype;
}

Phenotype &Entity::phenotype()
{
    mPhenotype;
}


