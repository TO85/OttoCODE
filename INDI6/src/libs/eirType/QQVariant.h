#pragma once
#include "eirType.h"

#include <QtCore/QVariant>

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QMetaType>
#include <QtCore/QPair>
#include <QtCore/QVariantMap>

#include "eirType/MultiName.h"
#include "eirType/QQVector.h"

class EIRTYPE_EXPORT QQVariant : public QVariant
{
public:
    typedef MultiName Key;
    typedef QPair<MultiName, QQVariant> KeyValue;
    typedef QMap<MultiName, QQVariant> Map;
    typedef QList<QQVariant> List;
    typedef QList<Key> KeyList;
    typedef QList<KeyValue> KeyValueList;
    typedef QQVector<QQVariant> Vector;

public:
    QQVariant(const QVariant &other) : QVariant(other) {;}
    QQVariant(const char *pch) : QVariant(QString(pch)) {;}
    QQVariant(const signed i) : QVariant(i) {;}
    QQVariant() = default;
    QQVariant(const QQVariant &other) = default;
    ~QQVariant() = default;
    QQVariant &operator = (const QQVariant &other) = default;

public: // access
    QMetaType::Type type() const { return QMetaType::Type(QVariant::type()); }

public: // static
    QVariantMap toQMap(const QQVariant::Map &map);
    QVariantMap toQMap(const QQVariant::List &list);
    List toList(const QQVariant::Map &map);
    List toList(const QVariantMap &qmap);
    Map toMap(const QVariantMap &qmap);
    Map toMap(const QQVariant::List &list);
    KeyList allKeys(const QQVariant::List &list);
    KeyList allKeys(const QQVariant::Map &map);
    KeyList allKeys(const QVariantMap &qmap);
};

Q_DECLARE_METATYPE(QQVariant);
