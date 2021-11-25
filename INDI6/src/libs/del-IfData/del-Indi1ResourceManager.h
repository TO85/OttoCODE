#pragma once
#include "IfData.h"

#include <QObject>


#include <eirType/MultiName.h>
#include <eirType/QQFileInfo.h>
#include <eirXml/DomFile.h>
#include <eirXml/DomStatus.h>
#include <eirXml/QQDomDocument.h>
class DomFileManager;

#include "ResourceData.h"
class Indi1MainData;
class InputIndi1BitMask;
class OutputIndi1BitMask;
class WeightMaskIndi1MaskedFloatVector;
class MeanFaceIndi1MaskedFloatVector;
class FaceLayersIndi1MaskedFloatVectorSet;

class IFDATA_EXPORT Indi1ResourceManager : public QObject
{
    Q_OBJECT
public:
    explicit Indi1ResourceManager(QObject *parent = nullptr);

public:

public:
    void setConfiguration(const QVariantMap &aConfig);

public slots:

signals:

private:
    DomFile * domFile(const MultiName &aKey) const;

    DomStatus addFile(const QQString aFileName, const MultiName &aKey=MultiName());

:
    QVariantMap mConfig;
    QDir mBaseDir;
};




