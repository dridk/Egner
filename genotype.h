#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <QVector>
#include <QDebug>
class Genotype
{
public:
    Genotype(const QVector<int>& vector = QVector<int>(9,0));
    ~Genotype();
    int at(int x, int y);
    void set(int x, int y, int value);
    QString toString() const;
    int geneCount() const;
    const QVector<int> &toVector() const;
    void fromVector(QVector<int> vector);

    Genotype operator+(const Genotype& other);


private:
    QVector<int> mVector;
    int mGeneCount;

};

#endif // GENOTYPE_H
