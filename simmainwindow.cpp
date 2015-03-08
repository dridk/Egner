#include "simmainwindow.h"
#include "inittoolwidget.h"
#include "plottoolwidget.h"
#include <QInputDialog>
#include <QToolBar>
#include <QFileDialog>
#include "inittoolwidget.h"
#include "runtoolwidget.h"
#include "knockouttoolwidget.h"

SimMainWindow::SimMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mPopulation = new Population;
    mListWidget = new PopulationListWidget(mPopulation);
    QToolBar * mMainToolBar = new QToolBar;

    QAction * openAction = mMainToolBar->addAction("Open");
    QAction * saveAction = mMainToolBar->addAction("Save");
    QAction * clearAction = mMainToolBar->addAction("Clear");


    addToolBar(mMainToolBar);
    setCentralWidget(mListWidget);


    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
    connect(clearAction,SIGNAL(triggered()),this,SLOT(clear()));

    addTool(new InitToolWidget);
    addTool(new RunToolWidget);
    addTool(new KnockoutToolWidget);


}

SimMainWindow::~SimMainWindow()
{

}

void SimMainWindow::addTool(AbstractToolWidget *tool)
{

    tool->setPopulation(mPopulation);
    QDockWidget * dock = new QDockWidget;
    dock->setWidget(tool);
    dock->setWindowTitle(tool->windowTitle());
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    connect(tool,SIGNAL(needRefresh()),this,SLOT(refresh()));

    mTools.append(tool);

}

void SimMainWindow::save()
{
    QString  filename = QFileDialog::getSaveFileName(this,"pop","/tmp/");

    if (!filename.isEmpty())
        mPopulation->save(filename);

    refresh();


}

void SimMainWindow::open()
{
    QString  filename = QFileDialog::getOpenFileName(this,"pop","/tmp/");

    if (!filename.isEmpty())
        mPopulation->load(filename);

    refresh();

}

void SimMainWindow::refresh()
{
    mListWidget->populate();

    foreach (AbstractToolWidget * t, mTools)
        t->refresh();
}

void SimMainWindow::clear()
{
    mPopulation->clear();
    refresh();


}


