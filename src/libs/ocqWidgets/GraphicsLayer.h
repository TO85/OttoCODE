#pragma once
#include "ocqWidgets.h"

#include <QGraphicsItemGroup>

#include <QGraphicsItem>

#include <Ident>

class OCQWIDGETS_EXPORT GraphicsLayer : public QGraphicsItemGroup
{
public:
    GraphicsLayer(const Ident id, QGraphicsItem * parent=nullptr);

private:
    Ident mIdent;
};

