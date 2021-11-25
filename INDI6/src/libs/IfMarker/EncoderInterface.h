#pragma once
#include "IfMarker.h"

#include "MarkerType.h"

class IFMARKER_EXPORT EncoderInterface
{
public:
    explicit EncoderInterface() = default;
    EncoderInterface(const EncoderInterface& other) = default;
    ~EncoderInterface() = default;
    EncoderInterface& operator = (const EncoderInterface& other) = default;

    virtual MarkerType sourceImage(const MarkerType aType) const = 0;

    virtual void configure(const SettingsSnapshot& globalConfig) {MUSTUSE(globalConfig);MUSTDO(it);}
    virtual void configure(const MarkerType aType, const SettingsSnapshot& globalConfig) {MUSTUSE(aType);MUSTUSE(globalConfig);MUSTDO(it);}
    virtual void clear() {MUSTDO(it);}
    virtual bool setImage(const QQImage& aImage, const DataMap& aData=DataMap()) {MUSTUSE(aImage);MUSTUSE(aData);MUSTDO(it);MUSTRTN(false);}
    virtual bool setData(const DataMap& aData) {MUSTUSE(aData);MUSTDO(it);MUSTRTN(false);}
    virtual int enqueue(const QQImage& frameImage, const SettingsSnapshot &localConfig, const DataMap& aData = DataMap(),
        const int priority=0) {MUSTUSE(frameImage);MUSTUSE(localConfig);MUSTUSE(aData);MUSTUSE(priority);MUSTDO(it);MUSTRTN(0);}
    virtual int enqueue(const SettingsSnapshot &localConfig, const DataMap &aData = DataMap(), const int priority = 0) {MUSTUSE(localConfig);MUSTUSE(aData);MUSTUSE(priority);MUSTDO(it);MUSTRTN(0);}
    virtual int enqueue(const DataMap &aData=DataMap(), const int priority=0) {MUSTUSE(aData);MUSTUSE(priority);MUSTDO(it);MUSTRTN(0);}

protected:
    virtual QQByteArray encode() = 0;

private:
    SettingsSnapshot mGlobalConfig;
    QMap<MarkerType, SettingsSnapshot> mTypeConfigMap;



public: // static
    static MarkerType::List supportedTypes();
    static bool supports(const MarkerType aType);

private: // static
    static MarkerType::List mSupportedTypes;
};

