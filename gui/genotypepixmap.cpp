#include "genotypepixmap.h"
#include <QPainter>
#include <QDebug>
GenotypePixmap::GenotypePixmap(const GenotypeNetwork& g, int size)
    :QPixmap(size,size)
{

    mGenotype = g;
    setRange(-20,20);
    draw();


}

GenotypePixmap::~GenotypePixmap()
{

}

void GenotypePixmap::setRange(qreal min, qreal max)
{
    mMin = min;
    mMax = max;

    draw();
}

void GenotypePixmap::draw()
{


    fill(Qt::white);
    int m = 2;
    int box = (width() - 10 )  / mGenotype.geneCount();
    QPainter painter(this);

    for (int x=0; x<mGenotype.geneCount(); ++x)
    {

        for (int y=0; y<mGenotype.geneCount(); ++y)
        {
            double value = mGenotype.at(x,y);
            painter.setBrush(QBrush(valueToColor(value)));
            QRect r(x*box, y*box, box,box);
            painter.drawRect(r);



            painter.drawText(r, Qt::AlignCenter,QString::number(mGenotype.at(x,y)));





        }


    }


    //    for (int x=0; x<width(); x+=box)
    //    {
    //        gy = 0;
    //        for (int y=0; y<width(); y+=box)
    //        {

    //           qDebug()<<mGenotype.at(2,2);

    //            painter.setBrush(valueToColor(0));
    //            painter.setPen(QPen(Qt::blue));
    //            painter.drawRect(QRect(x,y,box,box));

    //            gy++;

    //        }


    //        gx++;




    //    }




}

QColor GenotypePixmap::valueToColor(qreal x)
{


    if (x == 0)
        return Qt::darkGray;


    qreal newX = ( (x - mMin) / (mMax - mMin) ) * (1 - 0) ;




    double H = newX * 0.4; // Hue (note 0.4 = Green, see huge chart below)
    double S = 0.9; // Saturation
    double B = 0.9; // Brightness

    if (H < 0)
        H = 0;
    if (H > 1)
        H = 1;

    QColor c = QColor::fromHsvF(H,S,B);


    return c;


}

