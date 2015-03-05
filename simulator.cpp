#include "simulator.h"
#include <QDebug>
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

bool Simulator::run(int iteration)
{

    for (int i=0; i< iteration; ++i) {
        foreach (Entity * entity, mEntities) {

            qDebug()<<entity->name()<<" "<<entity->phenotype().hash();
            if (entity->run())
                entity->killLater();
        }

    }





}

