#include "populationlistwidget.h"

PopulationListWidget::PopulationListWidget(Population *pop, QWidget *parent) :
    QListWidget(parent)
{

    mPopulation = pop;
    setViewMode(QListView::IconMode);
    setIconSize(QSize(100,100));

    resize(400,600);
}

PopulationListWidget::~PopulationListWidget()
{

}

void PopulationListWidget::refresh()
{

    clear();
    double min = mPopulation->minValue();
    double max = mPopulation->maxValue();

    qDebug()<<min<<" "<<max;

    for (int i=0; i<mPopulation->count(); ++i)
    {

        QListWidgetItem * item = new QListWidgetItem;
        GenotypePixmap pix(mPopulation->at(i));
        pix.setRange(min,max);
        item->setText(QString::number(i));
        item->setIcon(QIcon(pix));
        item->setToolTip(mPopulation->at(i).raw());




        addItem(item);


    }






}

