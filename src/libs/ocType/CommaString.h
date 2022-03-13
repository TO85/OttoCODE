#pragma once

#include <QQString>

class CommaString : public QQString
{
public:
    CommaString() : QQString(',', QQString::sectionFlags(), QString()) {;}
    CommaString(const QString & other) : QQString(',', QQString::sectionFlags(), other) {;}
    CommaString(const char *psz) : QQString(',', QQString::sectionFlags(), QString(psz)) {;}
};

