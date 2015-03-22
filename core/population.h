#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QList>
#include <random>
#include <QObject>
#include "genotypeNetwork.h"

class Population : public QObject
{
    Q_OBJECT
public:
    Population(QObject * parent = 0);
    ~Population();

    void append(const GenotypeNetwork& e);
    void removeAt(int index);
    const GenotypeNetwork& at(int index) const;
    GenotypeNetwork& operator[](int i);
    int count() const;
    void clear();
    void init(int count, double mean=0, double sd=1, int geneCount=3, bool floating = false);
    void disable(int gene, int count);
    void disableAll(int gene);
    int geneCount() const;
    QString toString() const;
    QList<GenotypeNetwork> randomParent(int count = 2);
    GenotypeNetwork randomGenotype(double mean=0, double sd=1, int geneCount=3, bool floating=false) const;

    void load(const QString& filename);
    void save(const QString& filename);

    double minValue() const;
    double maxValue() const;
    double min(int x,int y) const;
    double max(int x, int y) const;
    double mean(int x, int y) const;
    double sd(int x,int y) const;

    void makeMutation(double proba, int step);
    void setReplicateAlgo(GenotypeNetwork::ReplicateAlgo algo);

    bool isAllSame();

public slots:
    void run(int iteration = 1);
    int next(double proba=0, int step = 1);


signals:
    void started();
    void running(int killed);
    void finished();


private:
    QList<GenotypeNetwork> mLists;
    GenotypeNetwork::ReplicateAlgo mAlgo;

};

#endif // SIMULATOR_H
