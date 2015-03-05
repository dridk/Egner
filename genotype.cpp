#include "genotype.h"
#include <QDebug>
#include <QtMath>

Genotype::Genotype(int geneCount)
{
    setGeneCount(geneCount);

}

Genotype::~Genotype()
{
    mVector.clear();
}

int Genotype::at(int x, int y)
{
    int index = mGeneCount * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");
    return mVector.at(index);

}

void Genotype::set(int x, int y, int value)
{
    int index = mGeneCount * y + x;
    Q_ASSERT_X(index >= 0 && index < mVector.length(), "Genotype at", "coord out of range");

    mVector[index] = value;
}

QString Genotype::toString() const
{
    QString out;
    for (int i=0; i<mVector.size(); ++i) {
        out.append(QString::number(mVector[i]));
        out.append(",");
        if (i%mGeneCount == mGeneCount-1)
            out.append("\n");
    }
    return out;
}

int Genotype::geneCount() const
{
    return qSqrt(mVector.count());
}

void Genotype::setGeneCount(int count)
{
    mVector.fill(0, count*count);
}

const QVector<int> &Genotype::toVector() const
{
    return mVector;
}

void Genotype::fromVector(QVector<int> vector)
{
    mVector = vector;
}

Genotype Genotype::operator+(const Genotype &other)
{

    Q_ASSERT_X(other.geneCount() == geneCount(), "Genotype","Genotype are not compatible. Not same matrix");

    QVector<int> vector;

    for (int i=0; i<geneCount()*geneCount(); i+=geneCount()){

        if(qrand()%2)
           vector<<other.toVector().mid(i,geneCount());
        else
           vector<<toVector().mid(i,geneCount());

    }


    Genotype newGenotype;
    newGenotype.fromVector(vector);
    return newGenotype;
}



