#ifndef KNOCKOUTTOOLWIDGET_H
#define KNOCKOUTTOOLWIDGET_H
#include "abstracttoolwidget.h"
#include <QtWidgets>
class KnockoutToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    KnockoutToolWidget(QWidget * parent = 0);
    ~KnockoutToolWidget();

public slots:
virtual void refresh();
    void apply();

private:
    QListWidget * mListWidget;
    QPushButton * mOkButton;




};

#endif // KNOCKOUTTOOLWIDGET_H
