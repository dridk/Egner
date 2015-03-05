#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "entity.h"
#include <QList>
#include <random>

class Simulator
{
public:
    Simulator();
    ~Simulator();

    void append(Entity * e);
    void removeOne(Entity* e);
    Entity *at(int index) const;
    Entity *operator[](int i);
    int count() const;
    void init(int count, int mean=0, int sd=1, int geneCount=3);
    bool run(int iteration = 1);


    QString toString() const;
    QList<Entity*> randomParent(int count = 2);

private:
    QList<Entity*> mEntities;
};

#endif // SIMULATOR_H
