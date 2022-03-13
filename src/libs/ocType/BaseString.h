#pragma once
//! \file BaseString.h Declarations of base QString enhanements

#include <QtCore/QString>

#include <QtCore/QObject>

class BaseString : public QString
{
    Q_GADGET

public:
    BaseString() {;}
};

