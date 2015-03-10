#include "genotypeNetwork.h"
#include <QDebug>
#include <QtMath>

GenotypeNetwork::GenotypeNetwork()
{
    setMutationProbability(1);
    setMutationRange(1);
}

GenotypeNetwork::GenotypeNetwork(const QVector<double> &v)
{
    mVector = v;
    setMutationProbability(1);
    setMutationRange(1);
}

GenotypeNetwork::GenotypeNetwork(const QString &raw)
{
    setMutationProbability(1);
    setMutationRange(1);

    int count = raw.split(",").size();
    Q_ASSERT_X(isSquare(count),"Genotype","data count should be squared");

    clear();
    QStringList list = raw.split(",");
    foreach (QString v, list)
        append(v.toDouble());


}

GenotypeNetwork::GenotypeNetwork(const QList<GenotypeNetwork> &parents)
{
    setMutationProbability(1);
    setMutationRange(1);







}

GenotypeNetwork::~GenotypeNetwork()
{
    clear();
}

double GenotypeNetwork::at(int x, int y) const
{
    int index = geneCount() * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");
    return mVector.at(index);

}

void GenotypeNetwork::set(int x, int y, double value)
{
    int index = geneCount() * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");

    mVector[index] = value;
}

void GenotypeNetwork::append(double value)
{
    mVector.append(value);
}


int GenotypeNetwork::geneCount() const
{
    return qSqrt(mVector.count());
}

void GenotypeNetwork::setGeneCount(int count)
{
    mVector.fill(0, count*count);
}

void GenotypeNetwork::setMutationProbability(double p)
{
    Q_ASSERT_X(p>=0 && p<=1, "Genotype::setMutationProbability", "probability should be in range 0 - 1");
    mMutationProbability = p;
}

void GenotypeNetwork::setMutationRange(double r)
{
    mMutationRange = r;
}

void GenotypeNetwork::mutate(double probability, double range)
{

    if (!probability)
        return;


    if (qrand()% int(probability*100))
    {
        int index = qrand()%(mVector.size());
        mVector[index] += (qrand()%2) == 0 ? range : -range;
    }


}

void GenotypeNetwork::disable(int gene)
{
    Q_ASSERT_X(gene >=0 && gene <= geneCount(), "GEnotypeNetwork::disable", "gene should be in range");

    for (int x=0; x<geneCount(); ++x)
    {
        set(x,gene,0);
    }

    for (int y=0; y<geneCount(); ++y)
    {
        set(gene,y,0);
    }
}

double GenotypeNetwork::min() const
{
    if (mVector.isEmpty())
        return 0;

    double min = mVector.first();

    foreach (double v, mVector)
        min = qMin(min,v);

    return min;

}

double GenotypeNetwork::max() const
{

    if (mVector.isEmpty())
        return 0;

     double max = mVector.first();

     foreach (double v, mVector)
         max = qMax(max,v);

     return max;

}


const QVector<double> &GenotypeNetwork::vector() const
{
    return mVector;
}



QString GenotypeNetwork::raw() const
{
    QStringList raw;
    foreach (double v , vector())
        raw.append(QString::number(v));
    return raw.join(",");
}



void GenotypeNetwork::clear()
{
    mVector.clear();
}

bool GenotypeNetwork::testViability(const Phenotype &phenotype) const
{
    if (mVector.isEmpty())
        return false;

    Phenotype currentPhenotype = phenotype;
    QSet<QString> history;

    QString current = currentPhenotype.raw();
    QString old;

    while (!history.contains(current)) {
        history.insert(currentPhenotype.raw());
        old = currentPhenotype.raw();
        currentPhenotype = currentPhenotype * (*this);
        current = currentPhenotype.raw();
    }
    if ( old == current)
        return true;

    return false;



}

bool GenotypeNetwork::testViability() const
{
    Phenotype p;
    for (int i=0; i<geneCount(); ++i){
        p.append(1);
    }

    return testViability(p);

}

Phenotype GenotypeNetwork::lastPhenotype()
{
    Phenotype p;
    for (int i=0; i<geneCount(); ++i){
        p.append(1);
    }

    return lastPhenotype(p);
}

Phenotype GenotypeNetwork::lastPhenotype(const Phenotype &phenotype)
{


    Phenotype currentPhenotype = phenotype;
    QSet<QString> history;

    QString current = currentPhenotype.raw();
    QString old;

    while (!history.contains(current)) {
        history.insert(currentPhenotype.raw());
        old = currentPhenotype.raw();
        currentPhenotype = currentPhenotype * (*this);
        current = currentPhenotype.raw();
    }
        return currentPhenotype;




}

GenotypeNetwork GenotypeNetwork::operator+(const GenotypeNetwork &other)
{

    return add(other);
}

GenotypeNetwork GenotypeNetwork::add(const GenotypeNetwork &other)
{
    Q_ASSERT_X(other.geneCount() == geneCount(), "Genotype","Genotype are not compatible. Not same matrix");
    QVector<double> v;

    for (int i=0; i<geneCount()*geneCount(); i+=geneCount()){

        if(qrand()%2)
            v<<other.vector().mid(i,geneCount());
        else
            v<<vector().mid(i,geneCount());

    }

    return GenotypeNetwork(v);
}

bool GenotypeNetwork::isSquare(int value)
{

    if ( (qSqrt(value) * qSqrt(value)) == value)
        return true;

    return false;


}



