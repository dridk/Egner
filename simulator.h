#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "entity.h"
#include <QList>

class Simulator
{
public:
    Simulator();
    ~Simulator();

    void addEntity(Entity * e);
    void remEntity(Entity* e);

    int count() const;

private:
    QList<Entity*> mEntities;
};

#endif // SIMULATOR_H
