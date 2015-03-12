#include "infotoolwidget.h"

InfoToolWidget::InfoToolWidget(QWidget * parent)
    :AbstractToolWidget(parent)
{

    mTextEdit = new QPlainTextEdit;

    QVBoxLayout * vl = new QVBoxLayout;
    vl->addWidget(mTextEdit);
    vl->setContentsMargins(0,0,0,0);
    setLayout(vl);

    mTextEdit->setReadOnly(true);

    setWindowTitle("Information");
}

InfoToolWidget::~InfoToolWidget()
{

}

void InfoToolWidget::refresh()
{

    mTextEdit->appendPlainText(QString("count:     %1").arg(population()->count()));
    mTextEdit->appendPlainText(QString("min value: %1").arg(population()->minValue()));
    mTextEdit->appendPlainText(QString("max value: %1").arg(population()->maxValue()));


    if (population()->count()>0){

        GenotypeNetwork g = population()->at(0);

        for (int x=0; x<g.geneCount(); ++x)
        {
            for (int y=0; y<g.geneCount(); ++y)
            {

                mTextEdit->appendPlainText(QString("== %1 - %2 ==").arg(x).arg(y));
                mTextEdit->appendPlainText(QString("mean: %1").arg(population()->mean(x,y)));
                mTextEdit->appendPlainText(QString("sd: %1").arg(population()->sd(x,y)));




            }
        }


    }



}

