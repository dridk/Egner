#include "entity.h"
#include <QUuid>
Entity::Entity(int geneCount)
{
    mPhenotype.setGeneCount(geneCount);
    mGenotype.setGeneCount(geneCount);
}

Entity::Entity(const Genotype &g)
{
    mGenotype  = g;
    mPhenotype.setGeneCount(g.geneCount());
}

Entity::Entity(const Genotype &g, Phenotype &p)
{
    mGenotype = g;
    mPhenotype = p;
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
    return mPhenotype;
}

bool Entity::isViable()
{
    QSet<QString> history;
    QString current = mPhenotype.raw();
    QString old;
    while (!history.contains(current)) {

        history.insert(mPhenotype.raw());
        old = mPhenotype.raw();
        mPhenotype = phenotype() * genotype();
        current = mPhenotype.raw();
    }

    if ( old == current)
        return true;
    else
        return false;
}

int Entity::geneCount()
{
    return genotype().geneCount();
}

Entity *Entity::childFromParent(const QList<Entity *> parents)
{
    if (parents.isEmpty())
        return 0;

    Genotype newGenotype = parents.first()->genotype();

    foreach ( Entity * parent, parents)
        newGenotype = newGenotype + parent->genotype();


    return new Entity(newGenotype);

}

const QString &Entity::name()
{
    return mName;
}

QString Entity::raw()
{
    QString out;
    out.append(genotype().raw());
    out.append("\\");
    out.append(phenotype().raw());

    return out;


}


