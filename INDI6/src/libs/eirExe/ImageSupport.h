#pragma once
#include "eirExe.h"

#include <QtCore/QByteArray>

#include <eirType/QQByteArrayList.h>
#include <eirType/QQStringList.h>

class EIREXE_EXPORT ImageSupport
{
public:
    typedef QQByteArrayList FormatNames;
    typedef QQStringList DirNameFilters;

public:
    ImageSupport() {;}

public:
    FormatNames supportedReaderFormats() const;
    QQByteArray supportedReaderFormatString() const;
    DirNameFilters supportedReaderDirNameFilters() const;
    DirNameFilters toDirNameFilters(FormatNames);
};

Q_GLOBAL_STATIC(ImageSupport, gsImageSupport);
