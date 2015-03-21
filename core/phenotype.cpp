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

int Phenotype::at(int i) const
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
    fill(1,count);
}

void Phenotype::fill(int value, int count)
{
    clear();
    mVector.fill(value,count);
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

Phenotype Phenotype::operator*(const GenotypeNetwork &other)
{

    return cross(other);

}

bool Phenotype::operator ==(const Phenotype &other) const
{

    if (geneCount() != other.geneCount())
        return false;

    for (int i=0; i<geneCount(); ++i)
    {
        if (at(i) != other.at(i))
            return false;
    }

    return true;


}

bool Phenotype::operator !=(const Phenotype &other) const
{
    return !((*this) == other);
}

Phenotype Phenotype::cross(const GenotypeNetwork &other)
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





