#include "Settings.h"

#include <QTemporaryDir>
#include <QTemporaryFile>

//#include <APP>
#include <eirXfr/Debug.h>

#include "AppSupport.h"

Settings::Settings(QObject *parent)
    : QSettings((new QTemporaryFile(qApp->applicationName()+"XXXXXX.ini"))->fileName(),
                QSettings::IniFormat, parent)
{
    TRACEQFI << QOBJNAME(parent);
}

void Settings::insert(const QQFileInfo &iniFileInfo)
{
    TRACEQFI << iniFileInfo;
    QSettings * pImportSettings = new QSettings(iniFileInfo.absoluteFilePath(),
                                               QSettings::IniFormat, this);
    foreach (MultiName key, pImportSettings->allKeys())
        insert(key, pImportSettings->value(key).toString());
    pImportSettings->deleteLater();
}

void Settings::insert(const QStringList &keyValueStrings)
{
    TRACEQFI << keyValueStrings;
    for (QString s : keyValueStrings)
        set(s);
    MUSTDO(it);
    MUSTUSE(keyValueStrings);
}


void Settings::insert(const QVariantMap &keyVariantMap)
{
    MUSTDO(it);
    MUSTUSE(keyVariantMap);

}

void Settings::set(const QQString &keyEqualsValu)
{
    TRACEQFI << keyEqualsValu;
    QQStringList qsl = keyEqualsValu.squeezed().split('=');
    if (qsl.isEmpty()) return;                                          /* /====\ */
    const MultiName key = qsl.takeFirst();
    const QQString tValu = qsl.isEmpty() ? "true" : qsl.first();
    set(key, tValu);
    TRACE << key() << tValu;
}

void Settings::insert(const MultiName &key, const QQString &valu)
{
    TRACEQFI << key() << valu;
    EMIT(importing(key, valu));
    setValue(key, valu);
}

bool Settings::contains(const MultiName &key) const
{
    return QSettings::contains(key);
}

void Settings::set(const MultiName &key, const QQString &valu)
{
    TRACEQFI << key() << valu;
    if (this->contains(key))
    {
        QQString oldValu = value(key).toString();
        EMIT(changing(key, valu, oldValu));
    }
    else
    {
        EMIT(creating(key, valu));
    }  // TODO see [#11] comment re {EMIT}s
    QSettings::setValue(key, valu);
}

void Settings::set(const MultiName &key, const QVariant &vari)
{
    MUSTDO(it);
    MUSTUSE(key);
    MUSTUSE(vari);
}

void Settings::setValue(const MultiName &key, const QVariant &vari)
{
    TRACEQFI << key() << vari;
    if (this->contains(key))
    {
        EMIT(changing(key, vari.toString(), valu(key)));
    }
    else
    {
        EMIT(creating(key, vari.toString()));
    }  // TODO see [#11] comment re {EMIT}s
    QSettings::setValue(key, vari);
}

void Settings::remove(const MultiName &key)
{
    TRACEQFI << key() << QSettings::contains(key);
    if ( ! QSettings::contains(key))    return;     /* /========\ */
    EMIT(removing(key, valu(key)));
    QSettings::remove(key);
}

void Settings::setDefault(const MultiName &key, const QQString &valu)
{
    MUSTDO(it);
    MUSTUSE(key);
    MUSTUSE(valu);

}

void Settings::setDefault(const MultiName& key, const QVariant &vari)
{
    MUSTDO(it);
    MUSTUSE(key);
    MUSTUSE(vari);

}

void Settings::beginGroup(const MultiName &key)
{
    TRACEQFI << key();
    QSettings::beginGroup(key());
    EMIT(groupChanging(MultiName(QSettings::group())));
}

void Settings::endGroup()
{
    TRACEFN;
    QSettings::endGroup();
    EMIT(groupChanging(MultiName(QSettings::group())));
}
/*
QQString QQString(const MultiName &key, const QQString &defaultValu) const
{
    QQString valu = value(key, defaultValu).toString();
    EMIT(getting(key, valu));
    TRACEQFI << key() << valu << defaultValu;
    return valu;
}
*/
QVariant Settings::vari(const MultiName &key, const QVariant &defaultVari) const
{
    QVariant vari = value(key(), defaultVari);
    //EMIT(getting(key, vari.toString()));
    TRACEQFI << key() << vari << defaultVari;
    return vari;
}

QVariantMap Settings::extract(const MultiName groupKey, const bool keepKey) const
{
    QVariantMap extractedMap;
    foreach (MultiName key, keys())
        if (key.startsWith(groupKey))
        {
            QQString extractValue = value(key).toString();
            MultiName extractKey = keepKey ? key : key.firstSegments(groupKey.segmentCount());
            extractedMap[extractKey] = extractValue;
        }
    return extractedMap;
}

QStringList Settings::toDebugStringList(const MultiName &groupKey)
{
    QStringList qsl;
    if ( ! groupKey.isEmpty()) beginGroup(groupKey);
    foreach (MultiName key, keys())
        qsl << QString("%1={%2}").arg(key).arg(valu(key));
    if ( ! groupKey.isEmpty()) endGroup();
    return qsl;
}

QStringList Settings::toDebugStringList(const QVariantMap &map)
{
    QStringList qsl;
    foreach (QString key, map.keys())
        qsl << QString("%1={%2}").arg(key).arg(map.value(key).toString());
    return qsl;
}

void Settings::dump(const MultiName &groupKey)
{
    foreach (QString s, toDebugStringList(groupKey)) DUMP << s;
}

// static
void Settings::dump(const QSettings::SettingsMap &map)
{
    foreach (QString key, map.keys())
        DUMP << QString("%1={%2}").arg(key).arg(map.value(key).toString());
}

bool Settings::boolean(const MultiName &key, const bool &defaultValue) const
{
    bool rtn = vari(key, defaultValue).toBool();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValue << ")";
    return rtn;
}

signed Settings::signedInt(const MultiName &key, const signed &defaultValue) const
{
    signed rtn = vari(key, defaultValue).value<signed>();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValue << ")";
    return rtn;
}

unsigned Settings::unsignedInt(const MultiName &key, const unsigned &defaultValue) const
{
    unsigned rtn = vari(key, defaultValue).value<unsigned>();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValue << ")";
    return rtn;
}

qreal Settings::real(const MultiName &key, const qreal &defaultValue) const
{
    qreal rtn = vari(key, defaultValue).value<qreal>();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValue << ")";
    return rtn;}

qreal Settings:: realPerMille(const MultiName &key, const signed &defaultValue) const
{
    signed rtn = vari(key, defaultValue).value<signed>();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValue << ")";
    return perMille(rtn);
}

QString Settings::string(const MultiName &key, const QString &defaultValu) const
{
    QString rtn = value(key, defaultValu).toString();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValu << ")";
    return rtn;
}

QQSize Settings::size(const MultiName &key, const QQSize &defaultValu) const
{
    QQSize rtn = vari(key, defaultValu).value<QSize>();
    DUMP << rtn << group() << key() << contains(key) << "(" << defaultValu << ")";
    return rtn;
}

// static
qreal Settings::perMille(const signed sValue, bool unitBound)
{
    qreal fValue = qreal(sValue) / 1000.0;
    return unitBound ? fValue : qBound(0.001, qreal(sValue) / 1000.0, 0.999);
}
