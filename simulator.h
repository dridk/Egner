#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "entity.h"
#include <QList>
#include <random>
#include <QObject>

class Simulator : public QObject
{
    Q_OBJECT
public:
    Simulator(QObject * parent = 0, int maxCount = 300);
    ~Simulator();

    void append(Entity * e);
    void removeOne(Entity* e);
    Entity *at(int index) const;
    Entity *operator[](int i);
    int count() const;
    int maxCount() const;
    void init(int count, int mean=0, int sd=1, int geneCount=3);
    void run(int iteration = 1);
    QString toString() const;
    QList<Entity*> randomParent(int count = 2);

signals:
    void started();
    void running();
    void finished();


private:
    QList<Entity*> mEntities;
    int mMaxCount;
};

#endif // SIMULATOR_H
