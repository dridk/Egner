#ifndef INITTOOLWIDGET_H
#define INITTOOLWIDGET_H

#include <QtWidgets>
#include "abstracttoolwidget.h"

class InitToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    InitToolWidget(QWidget * parent = 0);
    ~InitToolWidget();

protected slots:
    void populate();


private:
    QDoubleSpinBox * mMeanSpinBox;
    QProgressBar * mBar;
    QDoubleSpinBox * mSdSpinBox;
    QSpinBox * mCountSpinBox;
    QSpinBox * mGeneCountSpinBox;
    QPushButton * mOkButton;


};

#endif // INITTOOLWIDGET_H
