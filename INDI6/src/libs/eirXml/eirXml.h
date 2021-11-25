#pragma once

#include "eirXml_global.h"
#include "eirXml-Qt5-pch.h"
#include <eirXfr/Debug.h>
#include <eirType/MultiName.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQFileInfoList.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>

class QQDomElement;
class QQDomDocument;
class QQDomNode;
class DomStatus;

class EIRXML_EXPORT eirXml
{
public:
    eirXml() {;}

public: // static
    static DomStatus checkNodeName(const QQString &aWhatNode, const QQString &aExpected, const QQString &aActual);
    static DomStatus checkNodeName(const QQString &aWhatNode, const QQString &aExpected, const QDomNode &aNode);
    static DomStatus checkDoctypeNodeName(const QQString &aExpectedDoctype, const QQString &aWhatNode,
                                          const QQString &aExpectedNodeName, const QDomNode &aNode);
};

