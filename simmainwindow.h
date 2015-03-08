#ifndef SIMMAINWINDOW_H
#define SIMMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QListWidget>
#include "abstracttoolwidget.h"
#include "population.h"
#include "populationlistwidget.h"

class SimMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimMainWindow(QWidget *parent = 0);
    ~SimMainWindow();

    void addTool(AbstractToolWidget * tool);

public slots:
    void save();
    void open();
    void refresh();
    void clear();


private:
    Population * mPopulation;
    PopulationListWidget * mListWidget;

    QList<AbstractToolWidget*> mTools;


};

#endif // SIMMAINWINDOW_H
