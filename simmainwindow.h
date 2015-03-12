#ifndef SIMMAINWINDOW_H
#define SIMMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QListWidget>
#include "abstracttoolwidget.h"
#include "population.h"
#include "populationlistwidget.h"
#include "populationstatwidget.h"
#include "propertylistwidget.h"

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
    void setProgress(int value);


private:
    Population * mPopulation;
    PopulationListWidget * mListWidget;
    PopulationStatWidget * mStatWidget;



    PropertyListWidget * mPropertyWidget;
    QList<AbstractToolWidget*> mTools;


};

#endif // SIMMAINWINDOW_H
