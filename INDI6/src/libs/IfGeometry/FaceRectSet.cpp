#include "FaceRectSet.h"

QTransform FaceRectSet::smFullToTightXf;
QTransform FaceRectSet::smFullToHeadXf;
QTransform FaceRectSet::smTightToFullXf;
QTransform FaceRectSet::smTightToHeadXf;


void FaceRectSet::set(const FaceRectSet::Type faceType, const SCRect rc)
{

}

/* --------------------------------- private static ---------------------------------- */

void FaceRectSet::staticCtor()
{
    setFullToTight();
    setFullToHead();
    setTightToFull();
    setTightToHead();
}

void FaceRectSet::setFullToTight()
{

}

void FaceRectSet::setFullToHead()
{

}

void FaceRectSet::setTightToFull()
{

}

void FaceRectSet::setTightToHead()
{

}
