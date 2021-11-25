#include "BaseDocument.h"


BaseDocument::BaseDocument(QObject *parent)
    : DomFile(parent)
{
    setObjectName("BaseDocument");
}

BaseDocument::BaseDocument(const QQFileInfo &aFileInfo, QObject *parent)
    : DomFile(aFileInfo, parent)
{
    setObjectName("BaseDocument");

}

DomStatus BaseDocument::loadElements()
{
    TRACEQFI << key()();
    DomStatus result = validate();
    result.append(DomFile::load());
    QQDomElement tDE = document().firstChildElement();
    result.expect("Initial Element (%1)", tDE.notNull(), QtInfoMsg, QtWarningMsg);
    int tIndex = 0;
    while (tDE.notNull())
    {
        result.info("Element #%1: %2", ++tIndex, tDE.tagName());
        mElementList.append(tDE);
        tDE = tDE.nextSiblingElement();
    }
    result.dump();
    status().append(result);
    return result;
}

DomStatus BaseDocument::validate() const
{
    TRACEQFI << key()();
    DomStatus result;
    result.expect("Validate Doctype Name(%1)",
                  expectedDoctypeName() == document().doctypeName(),
                  QtInfoMsg, QtWarningMsg);
    result.expect("Validate Root Element TagName(%1)",
                  expectedRootElementTagName() == rootElement().tagName(),
                  QtInfoMsg, QtWarningMsg);
    result.dump();
    status().append(result);
    return result;
}

