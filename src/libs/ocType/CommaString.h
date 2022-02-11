#pragma once

#include <String>

class CommaString : public String
{
public:
    CommaString() : String(',', String::sectionFlags(), QString()) {;}
    CommaString(const QString & other) : String(',', String::sectionFlags(), other) {;}
    CommaString(const char *psz) : String(',', String::sectionFlags(), QString(psz)) {;}
};

