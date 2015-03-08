#ifndef RUNTOOLWIDGET_H
#define RUNTOOLWIDGET_H
#include "abstracttoolwidget.h"
#include <QtWidgets>
#include "qcustomplot.h"
class RunToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    RunToolWidget(QWidget * parent = 0);
    ~RunToolWidget();

public slots:
    void run();
    void showPlot();


private:
    QSpinBox * mIterationBox;
    QSpinBox * mParentCountBox;
    QPushButton * mRunButton;
    QProgressBar * mBar;
    QCustomPlot * mPlot;

    QVector<double> mX;
    QVector<double> mY;

};

#endif // RUNTOOLWIDGET_H
