#include "simmainwindow.h"
#include "inittoolwidget.h"
#include "plottoolwidget.h"

#include <QInputDialog>
SimMainWindow::SimMainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    mSimulator = new Population;

    mToolBox = new QToolBox;
    mToolBar = new QToolBar;
    mProgressBar = new QProgressBar;


    QVBoxLayout * cLayout = new QVBoxLayout;
    cLayout->addWidget(mToolBox);
    //    cLayout->addWidget(mProgressBar);
    cLayout->setContentsMargins(0,0,0,0);

    QWidget * cw = new QWidget;
    cw->setLayout(cLayout);

    addToolBar(mToolBar);

    QAction * runAction = mToolBar->addAction("Run");
    QAction * obsAction = mToolBar->addAction("Observer");
    mToolBar->addWidget(mProgressBar);

    mToolMenu = new QMenu();
    obsAction->setMenu(mToolMenu);


    addTool(new InitToolWidget());
    addTool(new PlotToolWidget());



    setCentralWidget(cw);


    connect(runAction,SIGNAL(triggered()),this,SLOT(run()));
    connect(mSimulator,SIGNAL(finished()),this,SLOT(finnished()));
    connect(mSimulator,SIGNAL(running(int)),this,SLOT(running(int)));


}

SimMainWindow::~SimMainWindow()
{

}

void SimMainWindow::addTool(AbstractToolWidget *tool)
{

    mToolBox->addItem(tool, tool->windowIcon(),tool->windowTitle());
    mToolMenu->addAction(tool->windowTitle())->setCheckable(true);
    tool->setSimulator(mSimulator);

}


void SimMainWindow::run()
{
    bool ok;
    int iteration = QInputDialog::getInt(this,"step","step count",mProgressBar->maximum(),1,1000,1,&ok);
    if (ok){
        mCurrentStep = 0;
        mProgressBar->setRange(0, iteration);
        mSimulator->run(iteration);


    }
}

void SimMainWindow::started()
{
    mProgressBar->setFormat("Started...");
}

void SimMainWindow::finnished()
{
    mProgressBar->setFormat("Finished");

}

void SimMainWindow::running(int killed)
{
    mCurrentStep++;
    mProgressBar->setFormat("Step %p%");
    mProgressBar->setValue(mCurrentStep);
}



