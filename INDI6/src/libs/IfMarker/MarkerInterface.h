#pragma once
#include "IfMarker.h"


#include "MarkerType.h"

class IFMARKER_EXPORT MarkerInterface
{
protected:
    explicit MarkerInterface() = default;
    MarkerInterface(const MarkerInterface& other) = default;
    ~MarkerInterface() = default;
    MarkerInterface& operator = (const MarkerInterface& other) = default;

    virtual MarkerType sourceImage(const MarkerType aType) const = 0;

    virtual void configure(const SettingsSnapshot& globalConfig) {MUSTUSE(globalConfig);MUSTDO(it);}
    virtual void configure(const MarkerType aType, const SettingsSnapshot& typeConfig)  {MUSTUSE(aType);MUSTUSE(typeConfig);MUSTDO(it);}
    virtual bool setFrameImage(const QQImage& frameImage) {MUSTUSE(frameImage);MUSTDO(it);MUSTRTN(false);}
    virtual bool setFaceImage(const QQImage& faceImage) {MUSTUSE(faceImage);MUSTDO(it);MUSTRTN(false);}
    virtual bool setNormalImage(const QQImage& normalImage) {MUSTUSE(normalImage);MUSTDO(it);MUSTRTN(false);}
    virtual QImage mark(const MarkerType aType, const SettingsSnapshot& localConfig,
        const FrameData& frameData, const FaceData& faceData = FaceData()) = 0;

private:
    SettingsSnapshot mGlobalConfig;
    QMap<MarkerType, SettingsSnapshot> mTypeConfigMap;

public: // static
    static MarkerType::List supportedTypes();
    static bool supports(const MarkerType aType);

private: // static
    static MarkerType::List mSupportedTypes;

};

