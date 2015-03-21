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
    void showHist();
    void clearGraph();

    void getColor();
    void setColor(const QColor &col);


private:
    QSpinBox * mIterationBox;
    QSpinBox * mParentCountBox;
    QDoubleSpinBox * mMutationBox;
    QSpinBox * mStepBox;
    QLabel * mConvergeLabel;

    QPushButton * mRunButton;
    QPushButton * mClearGraph;
    QToolButton * mColorButton;
    QProgressDialog * mProgressDialog;
    QCustomPlot * mPlot;
    QCustomPlot * mHistPlot;
    QCheckBox * mPlotBox;
    QComboBox * mAlgoBox;
    QCheckBox * mHistBox;
    QColor mCurrentColor;


    QVector<double> mX;
    QVector<double> mY;
    int mTotalKilled;

};

#endif // RUNTOOLWIDGET_H
