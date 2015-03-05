#include "entity.h"
#include <QUuid>
Entity::Entity(int geneCount)
{
    mKill = false;
    mName = QUuid::createUuid().toString();

    mPhenotype.setGeneCount(geneCount);
    mGenotype.setGeneCount(geneCount);
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

void Entity::killLater()
{
    mKill = true;
}

bool Entity::needKill()
{
    return mKill;
}

bool Entity::run()
{
    QString hashTemp = phenotype().hash();
    //Compute new phenotype
    mPhenotype = mPhenotype * mGenotype;

    if (phenotype().hash() != hashTemp) {

        if ( mHistory.contains(phenotype().hash()))
            return false;
        else {
            mHistory.insert(phenotype().hash());
           return true;
        }
    }

    return true;
}

const QString &Entity::name()
{
    return mName;
}


