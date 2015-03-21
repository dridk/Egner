#ifndef PLOTTOOLWIDGET_H
#define PLOTTOOLWIDGET_H
#include "abstracttoolwidget.h"
#include "qcustomplot.h"
class PlotToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    explicit PlotToolWidget(QWidget *parent = 0);
    ~PlotToolWidget();


public slots:
    void started();
    void running(int killed);
    void finished();

private:
    QCustomPlot * mPlot;
    QVector<double> mX;
    QVector<double> mY;
    int mStep = 0;
};

#endif // PLOTTOOLWIDGET_H
