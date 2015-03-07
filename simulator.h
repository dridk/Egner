#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QList>
#include <random>
#include <QObject>
#include "genotypeNetwork.h"

class Simulator : public QObject
{
    Q_OBJECT
public:
    Simulator(QObject * parent = 0);
    ~Simulator();

    void append(const GenotypeNetwork& e);
    void removeAt(int index);
    const GenotypeNetwork& at(int index) const;
    GenotypeNetwork& operator[](int i);
    int count() const;
    int maxCount() const;
    void setMaxCount(int c);
    void init(int count, double mean=0, double sd=1, int geneCount=3);
    QString toString() const;
    QList<GenotypeNetwork> randomParent(int count = 2);

    void load(const QString& filename);
    void save(const QString& filename);

public slots:
    void run(int iteration = 1);


signals:
    void started();
    void running(int killed);
    void finished();


private:
    QList<GenotypeNetwork> mLists;
    int mMaxCount;
};

#endif // SIMULATOR_H
