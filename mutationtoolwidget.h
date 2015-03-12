#ifndef MUTATIONTOOLWIDGET_H
#define MUTATIONTOOLWIDGET_H

#include <QtWidgets>

class MutationToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MutationToolWidget(QWidget *parent = 0);
    ~MutationToolWidget();


private:
    QDoubleSpinBox * mProbaBox;
    QDoubleSpinBox * mStepBox;
    QPushButton * mOkButton;



};

#endif // MUTATIONTOOLWIDGET_H
