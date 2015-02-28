#include "phenotype.h"

Phenotype::Phenotype(const QVector<int> &vector)
{
    mVector = vector;
    mGeneCount = mVector.length();
}

Phenotype::~Phenotype()
{
    mVector.clear();
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

void Phenotype::fromVector(QVector<int> vector)
{
    mVector = vector;
    mGeneCount = vector.length();
}

Phenotype Phenotype::operator*(const Genotype &other)
{
    Q_ASSERT_X(other.geneCount()==geneCount(), "Phenotype","Phenotype and genotype have not the same genecount");
    QVector<int> newVector(geneCount(),0);
    int index = 0;
    // Genotype cross Phenotype => Matrice cross Vector
    foreach (int m , other.toVector()){
        int key  = index / geneCount();
        int mod  = index % geneCount();
        int v = toVector().at(mod);

        newVector[key] += m * v;

        index++;
    }

    Phenotype newPhenotype(newVector);
    return newPhenotype;

}


