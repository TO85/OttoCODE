// file: {INDI6 repo}./src/libs/eirTypes/Enumeration.h
#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QString>

#include "Named.h"
#include "QQString.h"
#include "QQStringList.h"

/*! @class Enumeration
 *  @brief Base class for named enumerations.

@section Goals Goals
The following goals were used in the design of this facility.
-   Ability to declare static constants (enum is part of class)
-   Assignment and copy
-   Equality and ordering
-   isNull() and isValid()
-   Static lookup by name
-   first()/last() or min()/max()
-   increment/decrement or next()/previous()
-   use as switch case
-   usable in other libraries
-   default c'tor is null and not valid

@section Usage Usage
@subsection hFileUsage Derived class' h file
@code
#include <eirType/Enumeration.h>
#define ENUMCLASS_ENUM(NV) \
    NV(Null, = 0)  \
    NV(Minimum,)   \

class EIRTYPE_EXPORT EnumClass : public Enumeration
{
    DECLARE_ENUMERATION(EnumClass, ENUMCLASS_ENUM)
};

@endcode

@subsection cppFileUsage Derived class' cpp file
@code
#include "EnumClass.h"
DEFINE_ENUMERATION(EnumClass, ENUMCLASS_ENUM);
@endcode

*/
class EIRTYPE_EXPORT Enumeration
{
public:
    Enumeration(void);
    Enumeration(Named<int> * p, const int value);
    Enumeration(Named<int> * p, const QQString & name);
    Enumeration(const Enumeration & other);
    Enumeration & operator = (const Enumeration & other);
    bool isValid(void) const;
    bool notValid(void) const { return ! isValid(); }
    bool isNull(void) const;
    bool isEmpty(void) const;
    QQString nameOf(const int value) const;
    int valueOf(const QString & name) const;
    QQString name(void) const;
    int value(void) const;
    bool is(const int value) const;
    void set(const int value);
    void set(const QString & value);
    void invalidate(void);
    bool operator == (const Enumeration & other) const;
    bool operator < (const Enumeration & other) const;
    operator int (void) const;
    int operator() (void) const;
    Enumeration first(void) const;
    Enumeration last(void) const;
    Enumeration & operator ++ (void); // prefix ++e
    Enumeration operator ++ (int);  // postfix e++
    Enumeration & operator -- (void); // prefix --e
    Enumeration operator -- (int);  // postfix e--
    QList<int> values(void) const;
    QList<int> values(const QQString &aStartsWith) const;
    QList<Enumeration> list(void) const;
    QList<Enumeration> list(const QQString &aStartsWith) const;
    QQStringList nameFlags(int f);

public: // pseudo-static functions
    bool isValid(const QString & name);
    int value(const QString & name);
    QList<Enumeration> parse(const QString & string);
    int parseFlags(const QString & string);

protected:
    enum initializer { initialize };
    Enumeration(enum initializer i) { (void)i; }
    static void insert(const int value, const QString & name);

protected:
    int value_i;
    QQString name_s;
    Named<int> * name_map;
}; // Enumeration

#define ENUMERATION_VALUE(NAME, VALUE) \
    NAME VALUE,

#define ENUMERATION_INSERT(NAME, VALUE) \
    maps.insert(NAME, #NAME); \

#define INSERT_ENUMERATION(DEF) \
    DEF(ENUMERATION_INSERT) ; \

#define DECLARE_ENUMERATION(CLASS, DEF) \
    public: \
        enum type { DEF(ENUMERATION_VALUE) }; \
        CLASS(enum initializer i) : Enumeration(i) \
        { name_map = &maps; INSERT_ENUMERATION(DEF); } \
        CLASS(void) : Enumeration() {} \
        CLASS(const int value) : Enumeration(&maps, value) {} \
        CLASS(const QString & name) : Enumeration(&maps, name) {} \
        CLASS(const CLASS & other) : Enumeration(other) {;} \
        static QString enumName(void) { return enumName_s; } \
        static CLASS base(void) { return dummy; } \
    private: \
        static Named<int> maps; \
        static QString enumName_s; \
        static CLASS dummy; \

#define DEFINE_ENUMERATION(CLASS, DEF) \
    Named<int> CLASS::maps; \
    QString CLASS::enumName_s( #CLASS ); \
    CLASS CLASS::dummy(CLASS::initialize); \


