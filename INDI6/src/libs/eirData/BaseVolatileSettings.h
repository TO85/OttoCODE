#pragma once
#include "eirData.h"

class SettingsSnapshot;

class EIRDATA_EXPORT BaseVolatileSettings : public QObject
{
    Q_OBJECT

public:
    explicit BaseVolatileSettings(QObject *parent = nullptr);

public:
    bool isEmpty() const { return 0 == count();}
    int count() const;
    Value value(const Key &key, const Value &defValue=Value());
    QSettings &settings() const { return *mpSettings; }
    PairList extractPairs(const Key &aGroupKey=Key());
    QQStringList keyValueStringList(const Key &aGroupKey=Key());
    Map keyValueMap(const Key &aGroupKey=Key());
    QQString tempFileName() const;
    bool contains(const Key &aKey) const;
    bool missing(const Key &aKey) const { return ! contains(aKey); }


public:
    BaseVolatileSettings copy();
    BaseVolatileSettings copy(const Key &aGroupKey);
    void paste(const BaseVolatileSettings &other);

public slots:
    virtual void clear() { settings().clear(); }
    virtual void setValue(const Key &key, const Value &aValue);
    virtual void setFallback(const Key &key, const Value &aValue);
    void beginGroup(const Key &aGroupKey);
    void endGroup();

public: // static
    static QQString keyValueString(const Pair &aPair);

private:
    QSettings &settings() { AEXPECTPTR(mpSettings); return *mpSettings; }
    BaseVolatileSettings &it() { return *this; }

public:

signals:
    void constructed(QSettings * settings);
    void opened(const QQFileInfo fileInfo);
    void added(const Pair aPair);
    void replaced(const Pair aNewPair, const Value aOldValue);
    void removed(const Pair aRemovedPair);
    void groupBegan(const Key aGroupKey);
    void groupEnded(const Key aGroupKey);
    void atGroup(const Key aGroupKey);
    void atRoot();

private:
    QPointer<QSettings> mpSettings=nullptr;
    QPointer<QTemporaryFile> mpTempFile=nullptr;
    QQFileInfo mFileInfo;
};

