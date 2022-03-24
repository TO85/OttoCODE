#include "GraphicsLayer.h"


GraphicsLayer::GraphicsLayer(const Ident id, QGraphicsItem * parent)
    : QGraphicsItemGroup(parent)
    , mIdent(id)
{
}
