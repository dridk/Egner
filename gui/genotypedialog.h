#ifndef GENOTYPEDIALOG_H
#define GENOTYPEDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "genotypepixmap.h"

class GenotypeDialog : public QDialog
{
    Q_OBJECT
public:
    GenotypeDialog(const GenotypeNetwork& g, QWidget * parent = 0);
    ~GenotypeDialog();

public slots:
    void computePhenotype();

private:
    GenotypeNetwork mGenotype;
    QLabel * mLabel;
    QLineEdit * mPhenotypeEdit;
    QLineEdit * mResultsEdit;
};

#endif // GENOTYPEDIALOG_H
