#ifndef GENOTYPEWIDGET_H
#define GENOTYPEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include "genotype.h"
#include "zodiacgraph/scene.h"
#include "zodiacgraph/scenehandle.h"
#include "zodiacgraph/nodehandle.h"
#include "zodiacgraph/plughandle.h"


class GenotypeView : public QGraphicsView
{
public:
    GenotypeView(const Genotype& genotype,QWidget * parent=0);
    ~GenotypeView();

    void drawGenotype();

private:
    Genotype mGenotype;
    zodiac::Scene * mScene;
    zodiac::SceneHandle mSceneHandle;
};

#endif // GENOTYPEWIDGET_H
