#pragma once

#include <QVariant>

#include "Key.h"

class Variable
{
public:
    Variable(const Key &key, const QVariant &variant);
    Variable() = default;
    ~Variable() = default;
    Variable(const Variable &other) = default;
    Variable &operator = (const Variable &other) = default;

public:
    Key key() const;
    Key & key(const Key newKey);
    QVariant value() const;
    QVariant & value(const QVariant newValue);

private:
    Key mKey;
    QVariant mVariant;
};

Q_DECLARE_METATYPE(Variable);

