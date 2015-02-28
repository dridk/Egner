#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
class Genotype
{
public:
    Genotype(int geneCount = 3);
    Genotype(const QVector<int>& vector);
    ~Genotype();
    int at(int x, int y);
    void set(int x, int y, int value);
    QString toString() const;
    int geneCount() const;
    const QVector<int> &toVector() const;




private:
    QVector<int> mVector;
    int mGeneCount;

};

#endif // GENOTYPE_H
