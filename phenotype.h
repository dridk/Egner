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
    void append(int value);
    int geneCount() const;
    void setGeneCount(int count=3);
    const QVector<int>& vector() const;
    void fromVector(QVector<int> vector);
    void fromRaw(const QString& raw);
    QString raw() const;
    Phenotype operator*(const Genotype& other);
    void clear();


protected:
    int normalize(int value);




private:
    QVector<int> mVector;
};

#endif // PHENOTYPE_H
