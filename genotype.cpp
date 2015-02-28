#include "genotype.h"
#include <QDebug>
#include <QtMath>

Genotype::Genotype(const QVector<int> &vector)
{
    Q_ASSERT_X(qSqrt(vector.length()),"Genotype constructor", "Vector must be a pow of 2! Life 3x3=9 or 4x4=16");
    mVector = vector;
    mGeneCount = qSqrt(vector.length());
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
    out.append("\n");
    for (int i=0; i<mGeneCount*mGeneCount; ++i) {
        out.append(QString::number(mVector[i]));
        out.append(",");
        if (i%mGeneCount == mGeneCount-1)
            out.append("\n");
    }
    return out;
}

int Genotype::geneCount() const
{
    return mGeneCount;
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


return Genotype(vector);

}



