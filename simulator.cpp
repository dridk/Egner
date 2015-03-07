#include "simulator.h"
#include <QDebug>
#include <QFile>

Simulator::Simulator(QObject * parent)
    :QObject(parent)
{
    mMaxCount = 0;
}

Simulator::~Simulator()
{
    mLists.clear();
}

void Simulator::append(const GenotypeNetwork& e)
{
    mLists.append(e);
}

void Simulator::removeAt(int index)
{
    mLists.removeAt(index);
}

const GenotypeNetwork& Simulator::at(int index) const
{
    return mLists.at(index);
}

GenotypeNetwork& Simulator::operator[](int i)
{
    return mLists[i];
}

int Simulator::maxCount() const
{
    return mMaxCount;
}

void Simulator::setMaxCount(int c)
{
    mMaxCount = c;
}

int Simulator::count() const
{
    return mLists.count();
}

void Simulator::init(int count, double mean, double sd, int geneCount)
{
    setMaxCount(count);
    mLists.clear();
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean,sd);

    // Create 'count' entity....
    for (int i=0; i<maxCount(); ++i) {

        //Create random genotype
        GenotypeNetwork genotype;

        Phenotype lastPhenotype;
        lastPhenotype.fill(1, geneCount);

        while ((genotype.testViability() == false) || (genotype.lastPhenotype() != lastPhenotype)){
            genotype.clear();
            for (int j=0; j<geneCount * geneCount; ++j){
                double number = qRound(distribution(generator)*10);
                genotype.append(number);
            }
        }

        qDebug()<<genotype.lastPhenotype().raw();
        append(genotype);
    }

}

void Simulator::run(int iteration)
{

    emit started();



    for (int i=0; i<mLists.count()/2; ++i)
    {
        mLists[i].disable(1);
    }





    int totalKilled =0;


    for (int step=0; step<iteration ; ++step)
    {
        qDebug()<<QString("==== Step %1").arg(step);

        QList<GenotypeNetwork> nextGeneration;
        int killed = 0;


        while ( nextGeneration.count() < maxCount())
        {
            GenotypeNetwork maman = randomParent().first();
            GenotypeNetwork papa = randomParent().last();

            GenotypeNetwork child = maman + papa;

            if (child.testViability())
                nextGeneration.append(child);
            else
                killed++;

        }

        emit running(killed);
        totalKilled += killed;

        mLists.clear();
        mLists = nextGeneration;


        qDebug()<<QString("total: %2 total kill count:    %1").arg(killed).arg(mLists.size());
    }

    emit finished();

    qDebug()<<totalKilled;


}

QString Simulator::toString() const
{
    QString out;


    return out;

}

QList<GenotypeNetwork> Simulator::randomParent(int count)
{
    QVector<int> indexes;
    for (int i=0; i<mLists.size(); ++i)
        indexes.append(i);

    QList<GenotypeNetwork> parents;
    for (int j=0; j<count; ++j)
    {
        int id = qrand()%indexes.count();
        parents.append(mLists.at(indexes.takeAt(id)));
    }

    return parents;

}

void Simulator::load(const QString &filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    mLists.clear();
    QTextStream in(&file);

       while (!in.atEnd())
       {
           append(GenotypeNetwork(in.readLine()));

       }
    file.close();
}

void Simulator::save(const QString &filename)
{

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

     QTextStream out(&file);

      foreach (GenotypeNetwork g, mLists)
      {
          out<<g.raw()<<"\n";
      }



    file.close();

}
