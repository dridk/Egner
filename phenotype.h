#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <QVector>
#include "genotype.h"
class Phenotype
{
public:
    Phenotype(int geneCount=3);
    Phenotype(const QVector<int>& vector);
    ~Phenotype();
    int at(int i);
    void set(int i, int value);
    int geneCount() const;
    QString toString() const;
    const QVector<int>& toVector() const;



    Phenotype operator*(const Genotype& genotype);

private:
    QVector<int> mVector;
    int mGeneCount;


};

#endif // PHENOTYPE_H
