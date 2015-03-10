#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
#include "phenotype.h"
/*! \class GenotypeNetwork
 *  \brief represent a genotype network
 *
 * GenotypeNetwork is a 2D square matrix with dimension geneCount * geneCount
 *
 */
class Phenotype;
class GenotypeNetwork;
class GenotypeNetwork
{
public:
    GenotypeNetwork();
    GenotypeNetwork(const QVector<double>& v);
    GenotypeNetwork(const QString& raw);
    GenotypeNetwork(const QList<GenotypeNetwork>& parents);
    ~GenotypeNetwork();
    double at(int x, int y) const;
    void set(int x, int y, double value);
    void append(double value);
    int geneCount() const;
    void setGeneCount(int count=3);
    void setMutationProbability(double p);
    void setMutationRange(double r);
    void mutate(double probability=1, double range=1);
    void disable(int gene);
    double min() const;
    double max() const;

    const QVector<double> &vector() const;
    QString raw() const;
    void clear();

    bool testViability(const Phenotype& phenotype) const;
    bool testViability() const;
    Phenotype lastPhenotype();
    Phenotype lastPhenotype(const Phenotype& phenotype);



    GenotypeNetwork operator+(const GenotypeNetwork& other);
    GenotypeNetwork add(const GenotypeNetwork& other);


    static bool isSquare(int value);


private:
    QVector<double> mVector;
    double mMutationProbability;
    double mMutationRange;

};

#endif // GENOTYPE_H
