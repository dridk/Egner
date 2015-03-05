#include "genotypeview.h"

GenotypeView::GenotypeView(const Genotype& genotype,QWidget * parent)
    :QGraphicsView(parent)
{

    setRenderHint(QPainter::Antialiasing,true);

    mGenotype = genotype;
    mScene = new zodiac::Scene(this);
    setScene(mScene);

    mSceneHandle = zodiac::SceneHandle(mScene);

    drawGenotype();


}

GenotypeView::~GenotypeView()
{

}

void GenotypeView::drawGenotype()
{


    zodiac::NodeHandle fooNode = mSceneHandle.createNode("Foo");
    zodiac::NodeHandle barNode = mSceneHandle.createNode("Bar");

    zodiac::PlugHandle outPlug = fooNode.createOutgoingPlug("fooOut");
    zodiac::PlugHandle inPlug = barNode.createIncomingPlug("barIn");


    outPlug.connectPlug(inPlug);



}

