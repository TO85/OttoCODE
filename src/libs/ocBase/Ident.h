#pragma once

#include <QSharedDataPointer>
class IdentData;

class Uid;
class Key;
class QQString;
class StringList;

class Ident
{
public:
    Ident();
    Ident(const Ident &);
    Ident &operator=(const Ident &);
    ~Ident();

public:
    Uid uid() const;
    Uid uid(const Uid uid);
    Key key() const;
    Key key(const Key key);
    QQString name() const;
    QQString name(const QQString name) ;
    StringList description() const;
    StringList description(const StringList desc);

private:
    QSharedDataPointer<IdentData> data;
};

