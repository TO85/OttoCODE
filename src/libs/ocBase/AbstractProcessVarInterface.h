#pragma once
#include "ocBase.h"

#define AbstractProcessVarInterfaceId "org.OttoCODE.base.AbstractProcessVarInterface/1.0"

#include <QVariantMap>
#include <QVersionNumber>

#include "Key.h"
#include "KeyList.h"

class OCBASE_EXPORT AbstractProcessVarInterface
{
    virtual KeyList supportedProcesses() const = 0;
    virtual QString organization() const = 0;
    virtual QString application() const = 0;
    virtual QVersionNumber version() const = 0;
    virtual QVariant process(const Key processKey,
                                const QVariantMap parameterMap,
                                const QVariant inputData) const = 0;
};

Q_DECLARE_INTERFACE(AbstractProcessVarInterface, AbstractProcessVarInterfaceId)
