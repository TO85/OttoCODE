#pragma once
#include "IfMarker.h"

#include <eirType/Enumeration.h>

class IFMARKER_EXPORT MarkerType : public Enumeration
{
public:
    enum Type
    {
        $nullType = 0,
        $beginImgAcq = 10,
        RawCapture,
        $endImgAcq,
        $beginFrame = 20,
        MarkedFrame,
        NoFaceFrame,
        $endFrame,
        $beginFace = 100,
        MarkedFace,
        $endFace,
        $beginNormal = 190,
        Face,
        $endNormal,
        $endType
    };
    enum EmbedMethod
    {
        $nullEmbed = 0,
        Json,
        PureXml,
        XmlBase64,
        BinaryAttachmentXml,
        $endEmbed
    };
    typedef QList<Type> List;

public:
    MarkerType();


};

