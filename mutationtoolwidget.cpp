#include "mutationtoolwidget.h"

MutationToolWidget::MutationToolWidget(QWidget *parent) : AbstractToolWidget(parent)
{
    mProbaBox = new QDoubleSpinBox;
    mStepBox  = new QDoubleSpinBox;

    mOkButton = new QPushButton("Apply");
    connect(mOkButton,SIGNAL(clicked()),this,SLOT(makeMutation()));

    QFormLayout * fLayout = new QFormLayout;
    fLayout->addRow("Probability", mProbaBox);
    fLayout->addRow("Step",mStepBox);

    mProbaBox->setValue(1);
    mProbaBox->setSingleStep(0.1);
    mStepBox->setValue(1);

    QVBoxLayout * vLayout = new QVBoxLayout;
    vLayout->addLayout(fLayout);
    vLayout->addWidget(mOkButton);

    setLayout(vLayout);
    setWindowTitle("Mutation");


}

MutationToolWidget::~MutationToolWidget()
{

}

void MutationToolWidget::makeMutation()
{


    population()->makeMutation(mProbaBox->value(), mStepBox->value());
   emit needRefresh();


}

