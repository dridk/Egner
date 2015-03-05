#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
class Genotype
{
public:
    Genotype(int geneCount=3);
    ~Genotype();
    double at(int x, int y);
    void set(int x, int y, double value);
    void append(double value);
    int geneCount() const;
    void setGeneCount(int count=3);

    const QVector<double> &toVector() const;
    void fromVector(QVector<double> vector);

    QString toRaw() const;
    void fromRaw(const QString& raw);
    void clear();


    Genotype operator+(const Genotype& other);


private:
    QVector<double> mVector;

};

#endif // GENOTYPE_H
