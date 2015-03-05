#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <QVector>
#include "genotype.h"
class Phenotype
{
public:
    Phenotype();
    Phenotype(const QVector<int>& vector);
    Phenotype(const QString& raw);
    ~Phenotype();

    int at(int i);
    void set(int i, int value);
    void append(int value);
    int geneCount() const;
    void setGeneCount(int count=3);
    const QVector<int>& vector() const;

    QString raw() const;
    Phenotype operator*(const Genotype& other);
    void clear();


protected:
    int normalize(int value);




private:
    QVector<int> mVector;
};

#endif // PHENOTYPE_H
