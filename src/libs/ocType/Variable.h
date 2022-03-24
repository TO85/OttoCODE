#pragma once
#include "ocType.h"

#include <QMetaType>
#include <QVariant>

#include <Key>

class OCTYPE_EXPORT Variable
{
public:
    Variable(const Key &key, const QVariant &variant);

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    Key key() const;
    Key & key();
    QVariant vari() const;
    QVariant & vari();

private:
    Key mKey;
    QVariant mVariant;

public: // QMetaType
    Variable() = default;
    ~Variable() = default;
    Variable(const Variable &other) = default;
    Variable &operator = (const Variable &other) = default;
};

Q_DECLARE_METATYPE(Variable);

