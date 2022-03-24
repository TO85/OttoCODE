#pragma once
#include "ocColor.h"

#include <QMetaType>

#include "Color.h"

class OCCOLOR_EXPORT CompoundColor
{
public:
    CompoundColor(const Color::Compound cocom, const ColorFloatList &cfl);

private:
    ColorFloatList mColorFloatList;

public: // QMetaType
    CompoundColor() = default;
    ~CompoundColor() = default;
    CompoundColor(const CompoundColor &other) = default;
    CompoundColor &operator = (const CompoundColor &other) = default;
};

Q_DECLARE_METATYPE(CompoundColor);

