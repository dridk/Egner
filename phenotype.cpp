#include "phenotype.h"

Phenotype::Phenotype(int geneCount)
    :mGeneCount(geneCount)
{

    mVector.fill(0,mGeneCount);

}

Phenotype::Phenotype(const QVector<int> &vector)
{
    mVector = vector;
    mGeneCount = mVector.length();
}

Phenotype::~Phenotype()
{

}

int Phenotype::at(int i)
{
    return mVector.at(i);
}

void Phenotype::set(int i, int value)
{
    mVector[i] = value;
}

int Phenotype::geneCount() const
{
    return mGeneCount;
}

QString Phenotype::toString()const
{
    QString out;
    foreach (int value, mVector){
        out.append(QString::number(value));
        out.append(",");
    }
    return out;
}

const QVector<int>& Phenotype::toVector() const
{
    return mVector;
}

Phenotype Phenotype::operator*(const Genotype &genotype)
{

    Q_ASSERT_X(genotype.geneCount()==geneCount(), "Phenotype","Phenotype and genotype have not the same genecount");

    QVector<int> newVector(3,0);

    int index = 0;
    foreach (int m , genotype.toVector()){


            int key  = index / geneCount();
            int mod  = index % geneCount();

            int v = toVector().at(mod);

            newVector[key] += m * v;




        index++;

    }



    Phenotype newPhenotype(newVector);
    return newPhenotype;

}

