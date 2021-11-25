#pragma once
#include "IfData.h"

#include <eirType/MultiName.h>

#include <QtCore/QMetaType>

class ResourceType;

/*!
 * \brief The ResourceName class contains designations for the INDIface Resource Data.
 *
 * Format is: {ResourceType}/{DataSet}/{baseFileName}/{DataName}[/...{more}
 *
 */


class IFDATA_EXPORT ResourceName : public MultiName
{
public:
    ResourceName(const QString *aNames);
    explicit ResourceName() = default;
    ResourceName(const ResourceName &other) = default;
    ~ResourceName() = default;
    ResourceName &operator = (const ResourceName &other) = default;

public:
    ResourceType type() const;
    BasicName typeName() const { return segmentAt(0); }
    BasicName dataSet() const { return segmentAt(1); }
    BasicName baseFile() const { return segmentAt(2); }
    MultiName dataName() const { return segmentsMid(3); }
};

Q_DECLARE_METATYPE(ResourceName);

