#include "genotype.h"
#include <QDebug>
#include <QtMath>

Genotype::Genotype()
{
    setMutationProbability(1);
    setMutationRange(1);
}

Genotype::~Genotype()
{
    clear();
}

double Genotype::at(int x, int y)
{
    int index = geneCount() * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");
    return mVector.at(index);

}

void Genotype::set(int x, int y, double value)
{
    int index = geneCount() * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");

    mVector[index] = value;
}

void Genotype::append(double value)
{
    mVector.append(value);
}


int Genotype::geneCount() const
{
    return qSqrt(mVector.count());
}

void Genotype::setGeneCount(int count)
{
    mVector.fill(0, count*count);
}

void Genotype::setMutationProbability(double p)
{
    Q_ASSERT_X(p>=0 && p<=1, "Genotype::setMutationProbability", "probability should be in range 0 - 1");
    mMutationProbability = p;
}

void Genotype::setMutationRange(double r)
{
    mMutationRange = r;
}

void Genotype::mutate()
{

    if (!mMutationProbability)
        return;


    if (qrand()% int(mMutationProbability*100))
    {
        int index = qrand()%(mVector.size());
        mVector[index] += (qrand()%2) == 0 ? mMutationRange : -mMutationRange;
    }


}

const QVector<double> &Genotype::vector() const
{
    return mVector;
}

void Genotype::fromVector(QVector<double> vector)
{
    mVector = vector;
}

QString Genotype::raw() const
{
    QStringList raw;
    foreach (double v , vector())
        raw.append(QString::number(v));
    return raw.join(",");
}

void Genotype::fromRaw(const QString &raw)
{
    int count = raw.split(",").size();
    Q_ASSERT_X(isSquare(count),"Genotype::fromRaw","data count should be squared");

    clear();
    QStringList list = raw.split(",");
    foreach (QString v, list)
        append(v.toDouble());


}

void Genotype::clear()
{
    mVector.clear();
}

Genotype Genotype::operator+(const Genotype &other)
{

    Q_ASSERT_X(other.geneCount() == geneCount(), "Genotype","Genotype are not compatible. Not same matrix");
    QVector<double> v;

    for (int i=0; i<geneCount()*geneCount(); i+=geneCount()){

        if(qrand()%2)
            v<<other.vector().mid(i,geneCount());
        else
            v<<vector().mid(i,geneCount());

    }

    Genotype newGenotype;
    newGenotype.fromVector(v);
    return newGenotype;
}

bool Genotype::isSquare(int value)
{

    if ( (qSqrt(value) * qSqrt(value)) == value)
        return true;

    return false;


}



