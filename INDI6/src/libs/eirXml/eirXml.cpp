#include "eirXml.h"

#include <eirXfr/Debug.h>

#include "DomStatus.h"
#include "QQDomDocument.h"

DomStatus eirXml::checkNodeName(const QQString &aWhatNode,
                                    const QQString &aExpected, const QQString &aActual)
{
    DomStatus result;
    WEXPECTEQ(aExpected, aActual);
    if (aExpected == aActual)
        result.info("Processing %1 with %2", aWhatNode, aActual);
    else
        result.warn("Expectation failed loading %1: Expected=[%2] Actual=[%3]",
                    aWhatNode, aExpected, aActual);
    return result;
}

DomStatus eirXml::checkNodeName(const QQString &aWhatNode, const QQString &aExpected, const QDomNode &aNode)
{
    return checkNodeName(aWhatNode, aExpected, aNode.nodeName());
}

DomStatus eirXml::checkDoctypeNodeName(const QQString &aExpectedDoctype, const QQString &aWhatNode,
                                       const QQString &aExpectedNodeName, const QDomNode &aNode)
{
    DomStatus result = checkNodeName(aWhatNode, aExpectedNodeName, aNode);
    QQDomDocument doc = aNode.ownerDocument();
    DomStatus::Item docItem;
    AEXPECTEQ(aExpectedDoctype, doc.doctypeName());
    if (aExpectedDoctype == doc.doctypeName())
        result.info("Processing %1 with doctype %2", aWhatNode, doc.doctypeName());
    else
        result.warn("Expectation failed loading doc for %1: Expected=[%2] Actual=[%3]",
                    aWhatNode, aExpectedDoctype, doc.doctypeName());
    result.dump();
    return result;
}
