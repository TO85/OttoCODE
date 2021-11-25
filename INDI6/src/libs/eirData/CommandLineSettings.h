#pragma once
#include "eirData.h"

#include "BaseVolatileSettings.h"

#include <eirType/QQStringList.h>
#include <eirType/QQVariant.h>

class EIRDATA_EXPORT CommandLineSettings : public BaseVolatileSettings
{
    Q_OBJECT
public:
    explicit CommandLineSettings(QObject *parent = nullptr);
    explicit CommandLineSettings(const QQStringList aList, QObject *parent = nullptr);

public slots:
    void clear();
    void set(const QQStringList aList, const bool clearFirst=true);

signals:
    void added(const QQVariant::Key &key, const QQVariant &vari);

private:
    void append(const QQVariant::KeyValue &keyValue);
    static QQVariant::KeyValue split(const QQString &aString);

private:
    QQStringList mOtherStrings;
};

