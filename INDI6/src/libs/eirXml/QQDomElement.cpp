#include "QQDomElement.h"
#include "eirXml.h"

#include "QQDomNode.h"

QQStringList QQDomElement::attributeNameValueList() const
{
    TRACEQFI << tagName();
    QQStringList result;
    const QDomNamedNodeMap map = attributes();
    const int nNodes = map.count();
    for (int ix = 0; ix < nNodes; ++ix)
    {
        QQDomNode node = map.item(ix);
        QQString name = node.nodeName();
        QQString value = node.nodeValue();
        result << QQString("[%1]=[%2]").arg(name, value);
    }
    return result;
}

QQStringList QQDomElement::childElementNameList() const
{
    TRACEQFI << tagName();
    QQStringList result;
    const QDomNodeList nodes = childNodes();
    const int nNodes = nodes.count();
    for (int ix = 0; ix < nNodes; ++ix)
    {
        QQDomNode node = nodes.item(ix);
        if (node.isElement())
        {
            QQString name = node.nodeName();
            result << name;
        }
    }
    return result;
}

QQStringList QQDomElement::toInfoStrings(const int level) const
{
    QQStringList result;
    result << QQString("Tag: %1").formatMessage(tagName());
    if (level >= 1)
    {
        result << QQString("Attributes: %1").formatMessage(attributeCount());
        if (level >= 2)
            result << attributeNameValueList();
        result << QQString("Child Elements: %1").formatMessage(childElementNameList().count());
        if (level >= 2)
            result << childElementNameList();
    }
    return result;
}

QQDomElement QQDomElement::childElement(const QQString &elementTag) const
{
    TRACEQFI << elementTag;
    QQDomElement result = firstChildElement(elementTag);
    result.dump();
    return result;
}

QQStringList QQDomElement::toDebugStrings(const bool nest) const
{
    QQStringList result;
    result = toDebugStrings(0, nest);
    return result;
}

// private
QQStringList QQDomElement::toDebugStrings(const int nestLevel, const bool nest) const
{
    if (isNull()) return QQStringList() << "{QQDomElement null}";
    QQStringList result;
    const QQStringList tAttr = attributeNameValueList();
    const QQStringList tCEle = childElementNameList();
    QQString nestPrefix = QQString("%1%2%3")
            .arg(QQString(nestLevel * 4 - 2, QChar::Space),
                nestLevel ? QQString::number(nestLevel) : "",
                nestLevel ? ">" : "");
    result << nestPrefix << "{QQDomElement: " + tagName() + ">";
    if (tAttr.notEmpty())
    {
        result << nestPrefix << "{attributeNameValueList:>";
        result << nestPrefix << tAttr;
        result << nestPrefix << "<attributeNameValueList}";
    }
    if (tCEle.notEmpty())
    {
        result << nestPrefix << QQString("{Child Elements #%1:>").arg(nestLevel);
        result << nestPrefix << childElementNameList();
        if (nest)
        {
            for(QQDomElement de = firstChildElement(); !de.isNull(); de = de.nextSiblingElement())
                de.toDebugStrings(nestLevel + 1, nest);
        }
        result << nestPrefix << QQString("<Child Elements #%1}").arg(nestLevel);
    }
    result << "<QQDomElement}";
    return result;
}

void QQDomElement::dump(const bool nest) const
{
    for (auto s : toDebugStrings(nest))
        DUMP << s;
}

QDebug operator << (QDebug dbg, const QQDomElement &de)
{
    for (auto s : de.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
