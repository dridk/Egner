#include "knockouttoolwidget.h"

KnockoutToolWidget::KnockoutToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{
    mListWidget = new QListWidget;
    mOkButton = new QPushButton("Apply");

    QVBoxLayout * l = new QVBoxLayout;

    l->addWidget(mListWidget);
    l->addWidget(mOkButton);

    setWindowTitle("Knockout");
    setLayout(l);

    connect(mOkButton,SIGNAL(clicked()),this,SLOT(apply()));
}

KnockoutToolWidget::~KnockoutToolWidget()
{

}

void KnockoutToolWidget::refresh()
{

    if (population()->count() > 0)
    {

        mListWidget->clear();

        int geneCount = population()->at(0).geneCount();

        for (int i=0; i< geneCount; ++i)
        {

            QListWidgetItem * item = new QListWidgetItem;
            item->setText(QString("gene %1").arg(i));
            item->setData(Qt::UserRole,i);
            item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setCheckState(Qt::Unchecked);

            mListWidget->addItem(item);

        }





    }



}

void KnockoutToolWidget::apply()
{

    for (int i=0; i<mListWidget->count(); ++i){

        if (mListWidget->item(i)->checkState() == Qt::Checked)
        {
           population()->disableAll(mListWidget->item(i)->data(Qt::UserRole).toInt());
        }

    }

    emit needRefresh();


}

