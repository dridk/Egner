#include "population.h"
#include <QDebug>
#include <QFile>

Population::Population(QObject * parent)
    :QObject(parent)
{
    setReplicateAlgo(GenotypeNetwork::OneLine);
}

Population::~Population()
{
    mLists.clear();
}

void Population::append(const GenotypeNetwork& e)
{
    mLists.append(e);
}

void Population::removeAt(int index)
{
    mLists.removeAt(index);
}

const GenotypeNetwork& Population::at(int index) const
{
    return mLists.at(index);
}

GenotypeNetwork& Population::operator[](int i)
{
    return mLists[i];
}


void Population::clear()
{
    mLists.clear();
}

int Population::count() const
{
    return mLists.count();
}


GenotypeNetwork Population::randomGenotype(double mean, double sd, int geneCount, bool floating) const
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::normal_distribution<double> distribution(mean,sd);

    GenotypeNetwork genotype;

    while ((genotype.testViability() == false)){
        genotype.clear();
        for (int j=0; j<geneCount * geneCount; ++j){
            double number;
            if (floating)
                number = distribution(generator);
            else
                number = qRound(distribution(generator)*10);

            genotype.append(number);
        }
    }

    return genotype;

}

void Population::init(int count, double mean, double sd, int geneCount, bool floating)
{
    mLists.clear();

    // Create 'count' entity....
    Phenotype refPhenotype;
    while (mLists.count() < count)
    {
        GenotypeNetwork genotype = randomGenotype(mean,sd,geneCount,floating);
        if (mLists.isEmpty())
            refPhenotype = genotype.lastPhenotype();

        if (genotype.lastPhenotype() == refPhenotype)
            append(genotype);

        emit initializing(mLists.count());

    }
}

void Population::disable(int gene, int count)
{
    Q_ASSERT_X(count<= mLists.count(), "Population::disable","count too large");

    for (int i=0; i<count; ++i)
    {
        mLists[i].disable(gene);

    }
}

void Population::disableAll(int gene)
{
    disable(gene, count());
}

int Population::geneCount() const
{
    if (mLists.isEmpty())
        return 0;

    return mLists.first().geneCount();

}

void Population::run(int iteration)
{

    emit started();

    for (int step=0; step<iteration ; ++step)
    {

        int killed = next();
        qDebug()<<QString("total: %2 total kill count:    %1").arg(killed).arg(mLists.size());

        emit running(killed);

    }

    emit finished();
}

int Population::next(double proba, int step)
{
    QList<GenotypeNetwork> nextGeneration;
    int killed = 0;
    while ( nextGeneration.count() < count())
    {

        QList<GenotypeNetwork> parents = randomParent();


        GenotypeNetwork maman = parents.first();
        GenotypeNetwork papa  = parents.last();

        GenotypeNetwork child = maman.add(papa);

        child.mutate(proba, step);

        Phenotype lastPhenotype;
        lastPhenotype.fill(1, child.geneCount());

        if (child.testViability()) {
            nextGeneration.append(child);
        }
        else {
            killed++;
            qDebug()<<"non viable"<<child.raw();
        }
    }

    // swap list
    mLists.swap(nextGeneration);

    return killed;
}

QString Population::toString() const
{
    QString out;


    return out;

}

QList<GenotypeNetwork> Population::randomParent(int count)
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



void Population::load(const QString &filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    mLists.clear();
    QTextStream in(&file);

    while (!in.atEnd())
    {
        //           qDebug()<<in.readLine().trimmed();
        append(GenotypeNetwork(in.readLine().trimmed()));

    }
    file.close();

    qDebug()<<mLists.count()<<" added";

}

void Population::save(const QString &filename)
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

double Population::minValue() const
{

    if (mLists.isEmpty())
        return 0;

    double min = mLists.first().min();

    foreach (GenotypeNetwork g, mLists)
        min = qMin(min, g.min());

    return min;


}

double Population::maxValue() const
{

    if (mLists.isEmpty())
        return 0;

    double max = mLists.first().max();

    foreach (GenotypeNetwork g, mLists)
        max = qMax(max, g.max());

    return max;


}

double Population::min(int x, int y) const
{
    if (mLists.count() <=0)
        return 0;

    double min = mLists.first().at(x,y);
    foreach (GenotypeNetwork g, mLists)
        min = qMin(min, g.at(x,y));

    return min;


}

double Population::max(int x, int y) const
{
    if (mLists.count() <=0)
        return 0;


    double max = mLists.first().at(x,y);
    foreach (GenotypeNetwork g, mLists)
        max = qMax(max, g.at(x,y));

    return max;

}

double Population::mean(int x, int y) const
{

    if (mLists.count() <=0)
        return 0;


    double sum = 0;
    foreach (GenotypeNetwork g, mLists)
        sum = g.at(x,y);

    return sum / double(geneCount());



}

double Population::sd(int x, int y) const
{

}

void Population::makeMutation(double proba, int step)
{

    for (int i=0; i<mLists.count(); ++i)
    {
        mLists[i].mutate(proba,step);
    }

}

void Population::setReplicateAlgo(GenotypeNetwork::ReplicateAlgo algo)
{
    mAlgo = algo;
}

bool Population::isAllSame()
{

    if (mLists.isEmpty())
        return false;

    GenotypeNetwork a = mLists.first();


    foreach (GenotypeNetwork b , mLists)
    {
        if (a != b)
            return false;
    }



    return true;
}
