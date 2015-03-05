#include "simulator.h"
#include <QDebug>
Simulator::Simulator(QObject * parent, int maxCount)
    :QObject(parent)
{
    mMaxCount = maxCount;
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

int Simulator::maxCount() const
{
    return mMaxCount;
}

int Simulator::count() const
{
    return mEntities.count();
}

void Simulator::init(int count, int mean, int sd, int geneCount)
{
    mMaxCount = count;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean,sd);

    // Create 'count' entity....
    for (int i=0; i<count; ++i) {

        //Create random genotype
        Genotype genotype;


        for (int j=0; j<geneCount * geneCount; ++j){
            double number = qRound(distribution(generator)*10);
            genotype.append(number);
        }

        append(new Entity(genotype));
    }

}

void Simulator::run(int iteration)
{
    emit started();

    for (int step=0; step<iteration ; ++step)
    {
        qDebug()<<QString("==== Step %1").arg(step);

        QList<Entity*> nextGeneration;
        int killCount = 0;

        emit running();

        while ( nextGeneration.count() < maxCount())
        {
            Entity * maman = randomParent().at(0);
            Entity * papa = randomParent().at(1);

            Genotype gChild = maman->genotype() + papa->genotype();

            Entity * child = new Entity(gChild);

            if (child->isViable())
                nextGeneration.append(child);
            else
                killCount++;

        }

        mEntities.clear();
        mEntities = nextGeneration;

        emit finished();

        qDebug()<<QString("total kill count:    %1").arg(killCount);
    }



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

