#pragma once
#include "ocImage.h"

#define AbstractImageProcessInterfaceId "org.OttoCODE.image.AbstractImageProcessInterface/1.0"

#include <QVariant>
#include <QVariantMap>
#include <QVersionNumber>

#include <ocBase/AbstractProcessVarInterface.h>
#include <ocBase/Key.h>
#include <ocBase/KeyList.h>

#include "BaseImage.h"

class OCIMAGE_EXPORT AbstractImageProcessInterface : AbstractProcessVarInterface
{
    virtual BaseImage processImage(const Key processKey,
                                const QVariantMap parameterMap,
                                const BaseImage inputData) const = 0;
    ~AbstractImageProcessInterface() {;}
};

Q_DECLARE_INTERFACE(AbstractImageProcessInterface, AbstractImageProcessInterfaceId)
