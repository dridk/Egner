#ifndef SIMMAINWINDOW_H
#define SIMMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QListWidget>
#include "population.h"
#include "abstracttoolwidget.h"
class SimMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimMainWindow(QWidget *parent = 0);
    ~SimMainWindow();

    void addTool(AbstractToolWidget * tool);

public slots:
    void run();


    void started();
    void running(int killed);
    void finnished();

private:
    Population * mSimulator;
    int mCurrentStep;

    QList<AbstractToolWidget*> mToolsWidget;
    QToolBox * mToolBox;
    QToolBar * mToolBar;
    QProgressBar * mProgressBar;
    QMenu * mToolMenu;
    QSpinBox * mSpinBox;

};

#endif // SIMMAINWINDOW_H
