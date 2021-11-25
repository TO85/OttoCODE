#pragma once
#include "eirXml.h"

class QQDomNode : public QDomNode
{
public:
    explicit QQDomNode() = default;
    QQDomNode(const QDomNode &other) : QDomNode(other) {;}
    QQDomNode(const QQDomNode &other) = default;
    ~QQDomNode() = default;
    QQDomNode &operator = (const QQDomNode &other) = default;
};

Q_DECLARE_METATYPE(QQDomNode);
