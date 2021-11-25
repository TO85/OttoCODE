#pragma once
#include "eirGui.h"

#include <eirType/QQString.h>

class EIRGUI_EXPORT Document
{
public:
    Document() : mpDocument(new QTextDocument) {;}
    Document(const QString &aString) : mpDocument(new QTextDocument) { mpDocument->setPlainText(aString); }

public:
    QQString operator () () const { return mpDocument->toPlainText();}

public:
    void clear() { delete mpDocument; mpDocument = nullptr; }

private:
    QTextDocument * mpDocument=nullptr;
};

