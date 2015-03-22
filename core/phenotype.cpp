#include "phenotype.h"

Phenotype::Phenotype()
{

}

Phenotype::Phenotype(const QVector<double> &vector)
{
    foreach( int v, vector)
        append(v);

}

Phenotype::Phenotype(const QString &raw)
{
    foreach (QString v, raw.split(","))
        append(v.toDouble());

}

Phenotype::~Phenotype()
{
    clear();
}

double Phenotype::at(int i) const
{
    return mVector.at(i);
}

void Phenotype::set(int i, double value)
{
    mVector[i] = value;
}

void Phenotype::append(double value)
{
    mVector.append(value);
}

int Phenotype::geneCount() const
{
    return vector().size();
}

void Phenotype::setGeneCount(int count)
{
    fill(1,count);
}

void Phenotype::fill(double value, int count)
{
    clear();
    mVector.fill(value,count);
}

const QVector<double>& Phenotype::vector() const
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

    QVector<double> newVector(geneCount(),0);
    int index = 0;
    // Genotype cross Phenotype => Matrice cross Vector
    foreach (double m , other.vector()){
        int key  = index / geneCount();
        int mod  = index % geneCount();
        double v = vector().at(mod);
        newVector[key] += m * v;
        index++;
    }

    return Phenotype(newVector);
}

void Phenotype::normalize()
{
   for (int i=0; i<mVector.size(); ++i)
   {
      mVector[i] = mVector[i] > 0 ? 1 : -1;
   }


}

void Phenotype::clear()
{
    mVector.clear();
}






