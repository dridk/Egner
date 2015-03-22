#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <QVector>
#include "genotypeNetwork.h"

/*! \class Phenotype
 *  \brief represent a phenotype normalized
 *
 * Phenotype is a vector of size = geneCount
 *
 */
class GenotypeNetwork;
class Phenotype;

class Phenotype
{
public:
    Phenotype();
    Phenotype(const QVector<double>& vector);
    Phenotype(const QString& raw);
    ~Phenotype();

    double at(int i) const;
    void set(int i, double value);
    void append(double value);
    int geneCount() const;
    void setGeneCount(int count=3);
    void fill(double value, int count=3);
    const QVector<double>& vector() const;
    QString raw() const;
    Phenotype operator*(const GenotypeNetwork& other);
    bool operator == (const Phenotype& other) const;
    bool operator != (const Phenotype& other) const;

    Phenotype cross(const GenotypeNetwork& other);

    void normalize();


    void clear();


protected:





private:
    QVector<double> mVector;
};

#endif // PHENOTYPE_H
