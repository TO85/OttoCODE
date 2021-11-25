#pragma once

#include "IfData_global.h"
#include "IfData-Qt5-pch.h"
#include <eirType/QQSize.h>
#include <eirXfr/Debug.h>
#include <eirXml/DomFileManager.h>
#include <eirXml/DomStatus.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>
#include <IfGeometry/EyeLine.h>

typedef qreal FloatPixel;
typedef QVector<FloatPixel> FloatVector;

class IFDATA_EXPORT IfData
{
public:
    IfData() {;}
};
