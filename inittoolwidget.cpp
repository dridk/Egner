#include "inittoolwidget.h"
#include <QDebug>
InitToolWidget::InitToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{

    mMeanSpinBox = new QDoubleSpinBox;
    mSdSpinBox= new QDoubleSpinBox;
    mCountSpinBox= new QSpinBox;
    mGeneCountSpinBox= new QSpinBox;


    mMeanSpinBox->setValue(0);
    mSdSpinBox->setValue(1);
    mCountSpinBox->setValue(10);
    mGeneCountSpinBox->setValue(3);
    mCountSpinBox->setRange(0,10000);

    QFormLayout * cLayout = new QFormLayout;

    cLayout->addRow("count", mCountSpinBox);
    cLayout->addRow("mean", mMeanSpinBox);
    cLayout->addRow("sd", mSdSpinBox);
    cLayout->addRow("gene count", mGeneCountSpinBox);


    setLayout(cLayout);


    setWindowTitle("Initialisation");


}

InitToolWidget::~InitToolWidget()
{

}

void InitToolWidget::started()
{

    qDebug()<<"INITIALISATION ";

    if (mCountSpinBox->value() == 0)
        return;

    int count = mCountSpinBox->value();
    double mean = mMeanSpinBox->value();
    double sd = mSdSpinBox->value();
    int geneCount = mGeneCountSpinBox->value();

    simulator()->init(count, mean, sd, geneCount);

    qDebug()<<"INITILISATION FINIS"<<simulator()->count();


}

