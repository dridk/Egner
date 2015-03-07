#ifndef INITTOOLWIDGET_H
#define INITTOOLWIDGET_H

#include <QtWidgets>
#include "abstracttoolwidget.h"

class InitToolWidget : public AbstractToolWidget
{
public:
    InitToolWidget(QWidget * parent = 0);
    ~InitToolWidget();

protected slots:
    virtual void started();

private:
    QDoubleSpinBox * mMeanSpinBox;
    QDoubleSpinBox * mSdSpinBox;
    QSpinBox * mCountSpinBox;
    QSpinBox * mGeneCountSpinBox;


};

#endif // INITTOOLWIDGET_H
