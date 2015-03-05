#include "genotype.h"
#include <QDebug>
#include <QtMath>

Genotype::Genotype(int geneCount)
{
    setGeneCount(geneCount);
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

const QVector<double> &Genotype::toVector() const
{
    return mVector;
}

void Genotype::fromVector(QVector<double> vector)
{
    mVector = vector;
}

QString Genotype::toRaw() const
{
    QStringList raw;
    foreach (double v , toVector())
        raw.append(QString::number(v));
    return raw.join(",");
}

void Genotype::fromRaw(const QString &raw)
{
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

    QVector<double> vector;

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



