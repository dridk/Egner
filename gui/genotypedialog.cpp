#include "genotypedialog.h"
#include <QMessageBox>
GenotypeDialog::GenotypeDialog(const GenotypeNetwork& g, QWidget * parent)
    :QDialog(parent)
{
    mGenotype = g;

    mPhenotypeEdit = new QLineEdit;
    mResultsEdit = new QLineEdit;
    mLabel = new QLabel;
    mRawEdit = new QLineEdit;

    mRawEdit->setReadOnly(true);
    mRawEdit->setText(g.raw());
    qDebug()<<mGenotype.raw();
    mLabel->setPixmap(GenotypePixmap(mGenotype,400));

    QVBoxLayout * l = new QVBoxLayout;
    l->addWidget(mRawEdit);
    l->addWidget(mLabel);
    l->addWidget(mPhenotypeEdit);
    l->addWidget(mResultsEdit);

    mResultsEdit->setReadOnly(true);

    setLayout(l);

    mPhenotypeEdit->setPlaceholderText("Test phenotype...");

    connect(mPhenotypeEdit,SIGNAL(returnPressed()),this,SLOT(computePhenotype()));

}

GenotypeDialog::~GenotypeDialog()
{

}

void GenotypeDialog::computePhenotype()
{

    Phenotype pheno(mPhenotypeEdit->text());

    if (pheno.geneCount() != mGenotype.geneCount()){
        QMessageBox::warning(this,"error","phenotype not compatible");
        return;
    }


    Phenotype r = mGenotype.lastPhenotype(pheno);

    mResultsEdit->setText(r.raw());



}

