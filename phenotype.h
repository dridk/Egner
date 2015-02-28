#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <QVector>
#include "genotype.h"
class Phenotype
{
public:
    Phenotype(const QVector<int>& vector = QVector<int>(3,0));
    ~Phenotype();
    int at(int i);
    void set(int i, int value);
    int geneCount() const;
    QString toString() const;
    const QVector<int>& toVector() const;
    void fromVector(QVector<int> vector);


    Phenotype operator*(const Genotype& other);


private:
    QVector<int> mVector;
    int mGeneCount;


};

#endif // PHENOTYPE_H
