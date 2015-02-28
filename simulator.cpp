#include "simulator.h"

Simulator::Simulator()
{

}

Simulator::~Simulator()
{

}

void Simulator::addEntity(Entity *e)
{
    mEntities.append(e);
}

void Simulator::remEntity(Entity *e)
{
    mEntities.removeOne(e);
}

int Simulator::count() const
{
    return mEntities.count();
}

