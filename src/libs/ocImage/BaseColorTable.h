#pragma once

#include "typedefs.h"

class BaseColorTable : public RgbList
{
public:

public:
    BaseColorTable();
    BaseColorTable(const RgbList other);

public:

public:
    QRgb & at(const quint8 index) { return operator[](index); }
    void set(const quint8 index, const QRgb value);

public: // static
    static BaseColorTable grey();

};

