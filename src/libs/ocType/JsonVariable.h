#pragma once
#include "ocType.h"

#include <QMap>
#include <QJsonValue>
#include <QMetaType>

#include <Key>

class OCTYPE_EXPORT JsonVariable
{
public:
    JsonVariable(const Key &key, const QJsonValue &value);

public: // const
    QJsonValue::Type type() const;
    bool isValid() const;
    bool notValid() const { return ! isValid(); }
    QString typeName() const;
    bool isInt() const;
    int toInt() const;
    double toDouble() const;
    QString toString() const;
    bool toBool() const;
    bool isNull() const;
    QJsonArray toArray() const;
    QJsonObject toObject() const;
    QString formatted() const;

public: // non-const
    void set(const Key &key, const QJsonValue &value);

public: // static
    static QString typeName(const QJsonValue::Type type);


public: // debug
    QString toDebugString() const;


private:
    Key mKey;
    QJsonValue mValue;

public: // MetaType
    JsonVariable() = default;
    ~JsonVariable() = default;
    JsonVariable(const JsonVariable &other) = default;
    JsonVariable &operator = (const JsonVariable &other) = default;

// ------ generated -------
public:
    const Key &key() const;
    void key(const Key &newKey);
    const QJsonValue &value() const;
    void value(const QJsonValue &newValue);
};

Q_DECLARE_METATYPE(JsonVariable);
