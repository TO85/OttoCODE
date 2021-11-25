#pragma once
#include "If1Resource.h"

#include <QObject>

class BaseDocument : public DomFile
{
    Q_OBJECT
public:
    explicit BaseDocument(QObject *parent = nullptr);
    BaseDocument(const QQFileInfo &aFileInfo, QObject *parent = nullptr);

public:
    DomStatus status() const { return mStatus; }

public:
    virtual DomStatus loadElements();
    virtual DomStatus parseElements() = 0;

private:
    DomStatus validate() const;
    DomStatus &status() { return mStatus; }

private:
    virtual const QQString expectedDoctypeName() const { return "INDIfaceData"; } // note: 'f'
    virtual const QQString expectedRootElementTagName() const { return "INDIFaceData"; } // note: 'F'

signals:

private:
    DomStatus mStatus;
    QQDomElement::List mElementList;

};

