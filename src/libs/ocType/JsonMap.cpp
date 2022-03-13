#include "JsonMap.h"

#include <QFile>
#include <QJsonDocument>

JsonMap::JsonMap(const QByteArray &utf8text)
{
    set(utf8text);
}

JsonMap::JsonMap(const QJsonArray &array)
{
    set(array);
}

JsonMap::JsonMap(const QJsonObject &object)
{
    set(object);
}

JsonMap::JsonMap(const QFileInfo &fi)
{
    set(fi);
}

QJsonValue::Type JsonMap::type() const
{
    return mContainerValue.type();
}

JsonVariable JsonMap::at(const Key &key) const
{
    return mKeyVariableMap.value(key);
}

KeyList JsonMap::allKeys() const
{
    return mKeyVariableMap.keys();
}

bool JsonMap::isParseError() const
{
    return QJsonParseError::NoError == mParseError.error;
}

void JsonMap::clear()
{
    mContainerValue = QJsonValue(QJsonValue::Undefined);
    mKeyVariableMap.clear();
    mParseError = QJsonParseError();
    mGroupKey.clear();
    mArrayKey.clear();
    mObjectKey.clear();
}

void JsonMap::insert(const JsonVariable &jvar)
{
    mKeyVariableMap.insert(jvar.key(), jvar);
}

bool JsonMap::set(const QByteArray &utf8text)
{
    clear();
    QJsonDocument tDoc = QJsonDocument::fromJson(utf8text, &mParseError);
    bool result = isParseError();
    if (result) result &= parse(tDoc);
    return result;
}

bool JsonMap::set(const QJsonArray &array)
{
    clear();
    QJsonDocument tDoc = QJsonDocument(array);
    return parse(tDoc);
}

bool JsonMap::set(const QJsonObject &object)
{
    clear();
    QJsonDocument tDoc = QJsonDocument(object);
    return parse(tDoc);
}

bool JsonMap::set(const QFileInfo &fi)
{
    clear();
    QString fileName = fi.filePath();
    qDebug() << Q_FUNC_INFO << fileName;
    QFile tFile(fileName);
    bool result = tFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if (result)
    {
        QByteArray tBA = tFile.readAll();
        result &= set(tBA);
    }
    return result;
}

bool JsonMap::parse(const QJsonDocument &doc)
{
    qDebug() << Q_FUNC_INFO << doc;
    if (doc.isNull() || doc.isEmpty()) return false;                    /* /====\ */
    Key tKey;
    if (doc.isArray())
    {
        parse(tKey, doc.array());
        mContainerValue = doc.array();
    }
    else // doc.isObject()
    {
        parse(tKey, doc.object());
        mContainerValue = doc.object();
    }
    return true;
}

void JsonMap::parse(const Key &key, const QJsonObject &object)
{
    qDebug() << Q_FUNC_INFO << key << object;
    const QStringList tObjectKeys = object.keys();
    for (auto okey : tObjectKeys)
    {
        const KeySeg tSeg(okey);
        const QJsonValue tValue = object.value(okey);
        qDebug() << tSeg << tValue << tValue.type() << JsonVariable::typeName(tValue.type());
        switch (tValue.type())
        {
        case QJsonValue::Object:    parse(key.appended(tSeg), tValue.toObject());   break;
        case QJsonValue::Array:     parse(key.appended(tSeg), tValue.toArray());    break;
        default:                    parse(key.appended(tSeg), tValue);              break;
        }
    }
}

void JsonMap::parse(const Key &key, const QJsonArray &array)
{
    qDebug() << Q_FUNC_INFO << key << array;
    const qsizetype n = array.count();
    const Key tKey = key.appended(KeySeg("#Count"));
    mKeyVariableMap.insert(tKey, JsonVariable(tKey, n));
    for (qsizetype ix = 0; ix < n; ++ix)
    {
        const QJsonValue tValue = array.at(ix);
        const KeySeg tSeg = QString("#%1").arg(ix, 5, 10, QChar('0'));
        switch (tValue.type())
        {
        case QJsonValue::Object:    parse(key.appended(tSeg), tValue.toObject());   break;
        case QJsonValue::Array:     parse(key.appended(tSeg), tValue.toArray());    break;
        default:                    parse(key.appended(tSeg), tValue);              break;
        }
    }
}

void JsonMap::parse(const Key &key, const QJsonValue &value)
{
    qDebug() << Q_FUNC_INFO << key << value << value.type()
             << JsonVariable::typeName(value.type());
    mKeyVariableMap.insert(key, JsonVariable(key, value));
}

QStringList JsonMap::toDebugStrings() const
{
    QStringList result;
    result << "Container Type: " + JsonVariable::typeName(type());
    const KeyList keys = allKeys();
    for (Key key : keys)
        result.append(at(key).toDebugString());
    return result;
}

void JsonMap::dump() const
{
    for (auto s : toDebugStrings())
        qDebug() << s;
}
