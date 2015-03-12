#ifndef INFOTOOLWIDGET_H
#define INFOTOOLWIDGET_H
#include "abstracttoolwidget.h"
#include <QtWidgets>
class InfoToolWidget : public AbstractToolWidget
{
    Q_OBJECT
public:
    InfoToolWidget(QWidget * parent = 0);
    ~InfoToolWidget();

public slots:
    void refresh();

private:
    QPlainTextEdit * mTextEdit;
};

#endif // INFOTOOLWIDGET_H
