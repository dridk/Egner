#ifndef ENTITY_H
#define ENTITY_H
#include "phenotype.h"
#include "genotype.h"

class Entity
{
public:
    Entity(int geneCount=3);
    ~Entity();

    Genotype &genotype();
    Phenotype &phenotype();




private:
    Genotype mGenotype;
    Phenotype mPhenotype;
};

#endif // ENTITY_H
