#pragma once
#include "ocBase.h"

#include <QByteArray>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QMetaType>

#include "Key.h"
#include "KeyList.h"
#include "KeyMap.h"
#include "KeySeg.h"
#include "KeySegList.h"
#include "JsonVariable.h"

class OCBASE_EXPORT JsonMap
{
public:
    JsonMap(const QByteArray &utf8text);
    JsonMap(const QJsonArray &array);
    JsonMap(const QJsonObject &object);
    JsonMap(const QFileInfo &fi);

public: // const
    QJsonValue::Type type() const;
    bool isArray() const;
    bool isObject() const;
    bool isValid() const;
    bool notValid() const { return ! isValid(); }
    bool contains(const Key &key) const;
    bool notContains(const Key &key) const { return ! contains(key); }
    JsonVariable at(const Key &key) const;
    JsonVariable at(const int arrayIndex) const;
    QJsonValue value(const Key &key) const;
    QJsonValue value(const int arrayIndex) const;
    int arrayCount() const;
    KeySegList keys() const;
    KeyList allKeys() const;
    bool isParseError() const;
    bool notParseError() const { return ! isParseError(); }
    QJsonParseError parseError() const;
    QString parseErrorString() const;
    Key currentGroup() const;
    QByteArray toUtf8text() const;
    JsonVariable operator [] (const Key &key) const { return at(key); }
    JsonVariable operator [] (const int arrayIndex) const { return at(arrayIndex); }

public: // non-const
    void clear();
    void insert(const JsonVariable &jvar);
    bool set(const QByteArray &utf8text);
    bool set(const QJsonArray &array);
    bool set(const QJsonObject &object);
    bool set(const QFileInfo &fi);
    void beginArray(const Key &key) const;
    void beginGroup(const Key &key) const;
    void beginObject(const Key &key) const;
    void pushGroup(const KeySeg &keySeg) const;
    void popGroup();
    void endArray();
    void endGroup();
    void endObject();

private:
    bool parse(const QJsonDocument &doc);
    void parse(const Key &key, const QJsonObject &object);
    void parse(const Key &key, const QJsonArray &array);
    void parse(const Key &key, const QJsonValue &value);

public: // debug
    QStringList toDebugStrings() const;
    void dump() const;

private:
    QJsonValue mContainerValue=QJsonValue(QJsonValue::Undefined);
    KeyMap<JsonVariable> mKeyVariableMap;
    QJsonParseError mParseError;
    Key mGroupKey;
    Key mArrayKey;
    Key mObjectKey;

public: // MetaType
    JsonMap() = default;
    ~JsonMap() = default;
    JsonMap(const JsonMap &other) = default;
    JsonMap &operator = (const JsonMap &other) = default;
};

Q_DECLARE_METATYPE(JsonMap);

