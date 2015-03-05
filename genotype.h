#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
class Genotype
{
public:
    Genotype();
    ~Genotype();
    double at(int x, int y);
    void set(int x, int y, double value);
    void append(double value);
    int geneCount() const;
    void setGeneCount(int count=3);
    void setMutationProbability(double p);
    void setMutationRange(double r);
    void mutate();

    const QVector<double> &vector() const;
    void fromVector(QVector<double> vector);

    QString raw() const;
    void fromRaw(const QString& raw);
    void clear();


    Genotype operator+(const Genotype& other);


    static bool isSquare(int value);


private:
    QVector<double> mVector;
    double mMutationProbability;
    double mMutationRange;

};

#endif // GENOTYPE_H
