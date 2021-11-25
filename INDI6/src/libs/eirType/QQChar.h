#pragma once
#include "eirType.h"

#include <QtCore/QChar>

#include <QtCore/QMetaType>

class EIRTYPE_EXPORT QQChar : public QChar
{
public:
    explicit QQChar() = default;
    QQChar(const QChar other) : QChar(other) {;}
    QQChar(const unsigned char other) : QChar(other) {;}
    QQChar(const QQChar &other) = default;
    ~QQChar() = default;
    QQChar &operator = (const QQChar &other) = default;
};

Q_DECLARE_METATYPE(QQChar);

