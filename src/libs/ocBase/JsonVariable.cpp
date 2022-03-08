#include "JsonVariable.h"

JsonVariable::JsonVariable(const Key &key, const QJsonValue &value)
    : mKey(key), mValue(value) {;}

QJsonValue::Type JsonVariable::type() const
{
    return value().type();
}

bool JsonVariable::isValid() const
{
    return QJsonValue::Undefined != value().type();
}

QString JsonVariable::typeName() const
{
    return typeName(type());
}

bool JsonVariable::isInt() const
{
    if (QJsonValue::Double != type())    return false;
    double tDouble = toDouble();
    if (tDouble != double(int(tDouble))) return false;
    return true;
}

int JsonVariable::toInt() const
{
    return value().toInt();
}

double JsonVariable::toDouble() const
{
    return value().toDouble();
}

QString JsonVariable::toString() const
{
    return value().toString();
}

bool JsonVariable::toBool() const
{
    return value().toBool();
}

QString JsonVariable::formatted() const
{
    const QJsonValue tValue = value();
    switch (tValue.type())
    {
    case QJsonValue::Array:         return "{Array}";
    case QJsonValue::Bool:          return tValue.toBool() ? "true" : "false";
    case QJsonValue::Double:        return isInt() ? QString::number(toInt())
                                                   : QString::number(tValue.toDouble());
    case QJsonValue::Null:          return "{Null}";
    case QJsonValue::Object:        return "{Object}";
    case QJsonValue::String:        return tValue.toString();
    case QJsonValue::Undefined:     return "{Undefined}";
    default:                        return "{Unknown}";
    }
}


/* ----------------------- static ------------------------ */

QString JsonVariable::typeName(const QJsonValue::Type type)
{
    QString result = "{invalid}";
    switch (type)
    {
    case QJsonValue::Array:     result = "Array";       break;
    case QJsonValue::Object:    result = "Object";      break;
    case QJsonValue::String:    result = "String";      break;
    case QJsonValue::Double:    result = "Double";      break;
    case QJsonValue::Bool:      result = "Bool";        break;
    case QJsonValue::Null:      result = "Null";        break;
    default:                                            break;
    }
    return result;
}

QString JsonVariable::toDebugString() const
{
    return QString("%1 = {%2} %3(%4)").arg(key()).arg(formatted())
            .arg(isInt() ? "Int" : typeName()).arg(type());
}

/* ----------------------- generated ------------------------ */

const Key &JsonVariable::key() const
{
    return mKey;
}

void JsonVariable::key(const Key &newKey)
{
    mKey = newKey;
}

const QJsonValue &JsonVariable::value() const
{
    return mValue;
}

void JsonVariable::value(const QJsonValue &newValue)
{
    mValue = newValue;
}


