#include "simmainwindow.h"
#include "inittoolwidget.h"
#include "plottoolwidget.h"
#include <QInputDialog>
#include <QToolBar>
#include <QFileDialog>
#include "inittoolwidget.h"
#include "runtoolwidget.h"
#include "knockouttoolwidget.h"
#include "mutationtoolwidget.h"
#include "infotoolwidget.h"

SimMainWindow::SimMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mPopulation = new Population;
    mListWidget = new PopulationListWidget(mPopulation);
    mStatWidget = new PopulationStatWidget(mPopulation);

    QToolBar * mMainToolBar = new QToolBar;
    QTabWidget * mTabWidget = new QTabWidget;


    mPropertyWidget = new PropertyListWidget;

    QAction * openAction = mMainToolBar->addAction("Open");
    QAction * saveAction = mMainToolBar->addAction("Save");
    QAction * clearAction = mMainToolBar->addAction("Clear");


    addToolBar(mMainToolBar);



    mTabWidget->addTab(mListWidget,"Grid");
    mTabWidget->addTab(mStatWidget,"Stat");


    setCentralWidget(mTabWidget);
    setStatusBar(new QStatusBar());



    QDockWidget * mLeftWidget = new QDockWidget;
    mLeftWidget->setWidget(mPropertyWidget);
    mLeftWidget->layout()->setContentsMargins(0,0,0,0);
    mLeftWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    mLeftWidget->setTitleBarWidget(new QWidget());
    addDockWidget(Qt::LeftDockWidgetArea, mLeftWidget);



    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
    connect(clearAction,SIGNAL(triggered()),this,SLOT(clear()));

    addTool(new InfoToolWidget);
    addTool(new MutationToolWidget());
    addTool(new KnockoutToolWidget());
    addTool(new InitToolWidget());
    addTool(new RunToolWidget());

   setStyleSheet("QMainWindow::separator {width:1px}");



}

SimMainWindow::~SimMainWindow()
{

}

void SimMainWindow::addTool(AbstractToolWidget *tool)
{

    tool->setPopulation(mPopulation);
    mPropertyWidget->addWidget(tool);
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
    mListWidget->refresh();
    //mStatWidget->refresh();

    foreach (AbstractToolWidget * t, mTools)
        t->refresh();
}

void SimMainWindow::clear()
{
    mPopulation->clear();
    refresh();


}

void SimMainWindow::setProgress(int value)
{
}


