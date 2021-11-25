#pragma once
/*! \file ResourceBaseData.h */
#include "IfData.h"

#include <QtCore/QString>

#include <eirType/BasicName.h>
#include <eirType/QQLine.h>
#include <eirType/QQSize.h>
#include <eirXml/QQDomElement.h>
#include <IfGeometry/EyeLine.h>

#include "AbstractResource.h"
#include "ResourceType.h"

class IFDATA_EXPORT ResourceBaseData : private AbstractResource
{
public:
    ResourceBaseData() {;}
    ResourceBaseData(const QQDomElement &aDE);

public: // getters
    const BasicName &name() const;
    const QString &description() const;
    const QQSize &normalSize() const;
    const EyeLine &normalEyeLine() const;

public: // [re]setters
    void setName(const BasicName &newName);
    void resetName();
    void setDescription(const QString &newDescription);
    void resetDescription();
    void setNormalSize(const QQSize &newNormalSize);
    void resetNormalSize();
    void setNormalEyeLine(const QQLine &newNormalEyeLine);
    void resetNormalEyeLine();

private:
    BasicName mName;
    QString mDescription;
    QQSize mNormalSize;
    EyeLine mNormalEyeLine;

    // AbstractResource interface
public:
    bool isNull() const override final;
    virtual bool isValid() const override final;
    virtual bool parse() override final;
    virtual QQStringList toInfoStrings(const int level=1) const override;
};



