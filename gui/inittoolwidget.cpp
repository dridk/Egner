#include "inittoolwidget.h"
#include <QDebug>
InitToolWidget::InitToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{

    mMeanSpinBox = new QDoubleSpinBox;
    mSdSpinBox= new QDoubleSpinBox;
    mCountSpinBox= new QSpinBox;
    mGeneCountSpinBox= new QSpinBox;
    mOkButton = new QPushButton("Generate");

    mMeanSpinBox->setValue(0);
    mSdSpinBox->setValue(1);
    mCountSpinBox->setValue(10);
    mGeneCountSpinBox->setValue(3);
    mCountSpinBox->setRange(0,10000);
    mSdSpinBox->setRange(0,10000);
    mSdSpinBox->setSingleStep(0.1);
    mMeanSpinBox->setSingleStep(0.1);

    QFormLayout * cLayout = new QFormLayout;

    cLayout->addRow("count", mCountSpinBox);
    cLayout->addRow("mean", mMeanSpinBox);
    cLayout->addRow("sd", mSdSpinBox);
    cLayout->addRow("gene count", mGeneCountSpinBox);

    QVBoxLayout * all = new QVBoxLayout;
    all->addLayout(cLayout);
    all->addWidget(mOkButton);



    setLayout(all);


    setWindowTitle("Initialisation");

    connect(mOkButton,SIGNAL(clicked()),this,SLOT(populate()));


}

InitToolWidget::~InitToolWidget()
{

}

void InitToolWidget::populate()
{

    if (mCountSpinBox->value() == 0)
        return;

    int count = mCountSpinBox->value();
    double mean = mMeanSpinBox->value();
    double sd = mSdSpinBox->value();
    int geneCount = mGeneCountSpinBox->value();

    population()->init(count, mean, sd, geneCount);

    emit needRefresh();



}


