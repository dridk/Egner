#ifndef ABSTRACTWATCHER_H
#define ABSTRACTWATCHER_H

#include <QObject>

class AbstractWatcher : public QObject
{
    Q_OBJECT
public:
    explicit AbstractWatcher(QObject *parent = 0);
    ~AbstractWatcher();


};

#endif // ABSTRACTWATCHER_H
