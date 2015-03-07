#ifndef LISTTOOLWIDGET_H
#define LISTTOOLWIDGET_H

#include <QWidget>
#include <QListWidget>
#include "abstracttoolwidget.h"
class ListToolWidget : public AbstractToolWidget
{
public:
    ListToolWidget(QWidget * parent = 0);
    ~ListToolWidget();

private:
    QListWidget * mListWidget;
};

#endif // LISTTOOLWIDGET_H
