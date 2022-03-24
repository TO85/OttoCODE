#pragma once
#include "ocColor.h"

#include <QColor>
#include <QList>
#include <QMetaType>
#include <QRgb>

class OCCOLOR_EXPORT RgbColorTable
{
public:
    enum Type
    {
        $nullType = 0,
        GreyScale255,
        GreyScale240,
        W3Colors,
        WebExtended,
        RGB332,
        $sizeType
    };
    typedef QList<QRgb> Table;

public:
    RgbColorTable(const int nColors) : mTable(nColors, QRgb(0)) {;}

public:
    bool isEmpty() const;
    bool notEmpty() const { return ! isEmpty(); }
    int colorCount() const;
    bool isValidIndex(const int ix);
    QRgb at(const int ix) const;
    Table table() const;
    QRgb operator () (const int ix) const { return at(ix); }
    Table operator () () const { return table(); }

public:
    void clear();
    void resize(const qsizetype nColors);
    QRgb & at(const int ix);
    void set(const int ix, const QRgb rgb);
    void generate(const Type type);
    QRgb & operator [] (const int ix) { return at(ix); }

private:
    Table mTable;

public: // QMetaType
    RgbColorTable() = default;
    ~RgbColorTable() = default;
    RgbColorTable(const RgbColorTable &other) = default;
    RgbColorTable &operator = (const RgbColorTable &other) = default;
};

Q_DECLARE_METATYPE(RgbColorTable);

