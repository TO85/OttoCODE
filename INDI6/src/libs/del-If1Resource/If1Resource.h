#pragma once

#include "If1Resource_global.h"

#include "./If1Resource-Qt5-pch.h"
#include <eirType/BasicName.h>
#include <eirType/MultiName.h>
#include <eirType/QQDir.h>
#include <eirType/QQSize.h>
#include <eirType/QQString.h>
#include <eirXfr/Debug.h>
#include <eirXml/DomFile.h>
#include <eirXml/DomFileManager.h>
#include <eirXml/DomStatus.h>
#include <eirXml/ElementAttributeMap.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>
#include <IfGeometry/EyeLine.h>

typedef qreal FloatPixel;
typedef QVector<FloatPixel> FloatVector;

class IF1RESOURCE_EXPORT If1Resource
{
public:
    If1Resource();
};
