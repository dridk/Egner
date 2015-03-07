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
    Phenotype(const QVector<int>& vector);
    Phenotype(const QString& raw);
    ~Phenotype();

    int at(int i) const;
    void set(int i, int value);
    void append(int value);
    int geneCount() const;
    void setGeneCount(int count=3);
    void fill(int value, int count=3);
    const QVector<int>& vector() const;
    QString raw() const;
    Phenotype operator*(const GenotypeNetwork& other);
    bool operator == (const Phenotype& other) const;
    bool operator != (const Phenotype& other) const;

    Phenotype cross(const GenotypeNetwork& other);


    void clear();


protected:
    int normalize(int value);




private:
    QVector<int> mVector;
};

#endif // PHENOTYPE_H
