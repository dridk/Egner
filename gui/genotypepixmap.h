#ifndef GENOTYPEPIXMAP_H
#define GENOTYPEPIXMAP_H
#include <QPixmap>
#include "genotypeNetwork.h"
class GenotypePixmap : public QPixmap
{
public:
    GenotypePixmap(const GenotypeNetwork& g, int size=100);
    ~GenotypePixmap();

    void setRange(qreal min, qreal max);

protected:
    void draw();
    QColor valueToColor(qreal x);

private:
    GenotypeNetwork mGenotype;
    qreal mMin, mMax;

};

#endif // GENOTYPEPIXMAP_H
