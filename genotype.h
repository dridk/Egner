#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
class Genotype
{
public:
    Genotype(int geneCount=3);
    ~Genotype();
    int at(int x, int y);
    void set(int x, int y, int value);
    QString toString() const;
    int geneCount() const;
    void setGeneCount(int count=3);

    const QVector<int> &toVector() const;
    void fromVector(QVector<int> vector);

    Genotype operator+(const Genotype& other);


private:
    QVector<int> mVector;
    int mGeneCount;

};

#endif // GENOTYPE_H
