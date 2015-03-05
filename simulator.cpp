#include "simulator.h"
#include <QDebug>
Simulator::Simulator()
{

}

Simulator::~Simulator()
{

}

void Simulator::append(Entity *e)
{
    mEntities.append(e);
}

void Simulator::removeOne(Entity *e)
{
    mEntities.removeOne(e);
}

Entity *Simulator::at(int index) const
{
    return mEntities.at(index);
}

Entity *Simulator::operator[](int i)
{
    return mEntities[i];
}

int Simulator::count() const
{
    return mEntities.count();
}

void Simulator::init(int count, int mean, int sd, int geneCount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean,sd);

    // Create 'count' entity....
    for (int i=0; i<count; ++i) {

        //Create random genotype
        Genotype genotype(geneCount);

        for (int j=0; j<geneCount * geneCount; ++j){
            double number = qRound(distribution(generator)*10);
            genotype.append(number);
        }
        append(new Entity(genotype));
    }

}




bool Simulator::run(int iteration)
{
    QList<Entity*> mNextEntities;






    return false;



}

QString Simulator::toString() const
{
    QString out;


    return out;

}

QList<Entity*> Simulator::randomParent(int count)
{
    QVector<int> indexes;
    for (int i=0; i<mEntities.size(); ++i)
        indexes.append(i);

    QList<Entity*> parents;
    for (int j=0; j<count; ++j)
    {
        int id = qrand()%indexes.count();
        parents.append(mEntities.at(indexes.at(id)));
        indexes.removeAt(id);
    }

    return parents;

}

