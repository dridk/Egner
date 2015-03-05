#include "phenotype.h"

Phenotype::Phenotype()
{
}

Phenotype::Phenotype(const QVector<int> &vector)
{
    foreach( int v, vector)
        append(v);

}

Phenotype::Phenotype(const QString &raw)
{
    foreach (QString v, raw.split(","))
        append(v.toInt());

}

Phenotype::~Phenotype()
{
    clear();
}

int Phenotype::at(int i)
{
    return mVector.at(i);
}

void Phenotype::set(int i, int value)
{
    mVector[i] = normalize(value);
}

void Phenotype::append(int value)
{
    mVector.append(normalize(value));
}

int Phenotype::geneCount() const
{
    return vector().size();
}

void Phenotype::setGeneCount(int count)
{
    clear();
    mVector.fill(1,count);
}

const QVector<int>& Phenotype::vector() const
{
    return mVector;
}

QString Phenotype::raw() const
{
    QStringList raw;
    foreach (int v, vector()){
        raw.append(QString::number(v));
    }
    return raw.join(",");
}

Phenotype Phenotype::operator*(const Genotype &other)
{
    Q_ASSERT_X(other.geneCount()==geneCount(), "Phenotype","Phenotype and genotype have not the same genecount");

    QVector<int> newVector(geneCount(),0);
    int index = 0;
    // Genotype cross Phenotype => Matrice cross Vector
    foreach (int m , other.vector()){
        int key  = index / geneCount();
        int mod  = index % geneCount();
        int v = vector().at(mod);
        newVector[key] += m * v;
        index++;
    }

    return Phenotype(newVector);

}

void Phenotype::clear()
{
    mVector.clear();
}

int Phenotype::normalize(int value)
{
    return value > 0 ? 1 : -1;
}





