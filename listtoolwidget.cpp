#include "listtoolwidget.h"
#include <QVBoxLayout>
ListToolWidget::ListToolWidget(QWidget * parent )
    :AbstractToolWidget(parent)
{
    mListWidget = new QListWidget;
    QVBoxLayout * cLayout = new QVBoxLayout;
    cLayout->addWidget(mListWidget);
    setLayout(cLayout);

    setWindowTitle("GeneNetwork List");


}

ListToolWidget::~ListToolWidget()
{

}

