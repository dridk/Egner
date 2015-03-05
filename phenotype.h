#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <QVector>
#include "genotype.h"
class Phenotype
{
public:
    Phenotype(int geneCount = 3);
    ~Phenotype();
    int at(int i);
    void set(int i, int value);
    int geneCount() const;
    void setGeneCount(int count=3);
    QString toString() const;
    const QVector<int>& toVector() const;
    void fromVector(QVector<int> vector);
    Phenotype operator*(const Genotype& other);
    QString hash() const;

    QVector<int> toNormalVector() const;





private:
    QVector<int> mVector;
};

#endif // PHENOTYPE_H
