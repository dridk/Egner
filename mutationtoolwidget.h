#ifndef MUTATIONTOOLWIDGET_H
#define MUTATIONTOOLWIDGET_H

#include <QtWidgets>
#include "abstracttoolwidget.h"
class MutationToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    explicit MutationToolWidget(QWidget *parent = 0);
    ~MutationToolWidget();

public slots:
    void makeMutation();

private:
    QDoubleSpinBox * mProbaBox;
    QDoubleSpinBox * mStepBox;
    QPushButton * mOkButton;



};

#endif // MUTATIONTOOLWIDGET_H
