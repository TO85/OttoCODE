#pragma once
#include "ocBase.h"

#define AbstractProcessMapInterfaceId "org.OttoCODE.base.AbstractProcessMapInterface/1.0"

#include <QVariantMap>
#include <QVersionNumber>

#include "Key.h"
#include "KeyList.h"

class OCBASE_EXPORT AbstractProcessMapInterface
{
    virtual KeyList supportedProcesses() const = 0;
    virtual QString organization() const = 0;
    virtual QString application() const = 0;
    virtual QVersionNumber version() const = 0;
    virtual QVariantMap process(const Key processKey,
                                const QVariantMap parameterMap,
                                const QVariantMap inputData) const = 0;
    ~AbstractProcessMapInterface() {;}
};

Q_DECLARE_INTERFACE(AbstractProcessMapInterface, AbstractProcessMapInterfaceId)
