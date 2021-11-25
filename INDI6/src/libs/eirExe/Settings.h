// file: {repo: EIRC5}./src/libs/eirExe/QSettings.h
#pragma once
#include "eirExe.h"

#include <QObject>
#include <QMap>
#include <QSettings>
#include <QString>
#include <QVariant>
class QTemporaryDir;
class QTemporaryFile;

#include <eirType/MultiName.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQSize.h>
#include <eirType/QQString.h>
#include <eirType/Rational.h>
class ApplicationHelper;

class EIREXE_EXPORT Settings : public QSettings
{
    Q_OBJECT
public:
    typedef QQString Valu;

public:
    explicit Settings(QObject *parent=nullptr);

public slots:
    void insert(const QQFileInfo &iniFileInfo);
    void insert(const QStringList &keyValueStrings);
    void insert(const QVariantMap &keyVariantMap);
    void set(const QQString &keyEqualsValu);
    void set(const MultiName &key, const QQString &valu);
    void set(const MultiName &key, const QVariant &vari);
    virtual void setValue(const MultiName &key, const QVariant &vari);
    virtual void remove(const MultiName &key);
    void setDefault(const MultiName &key, const QQString &valu);
    void setDefault(const MultiName &key, const QVariant &vari);
    void beginGroup(const MultiName &key);
    void endGroup();

signals:
    void getting(const MultiName &key, const QQString &valu);
    void importing(const MultiName &key, const QQString &valu);
    void creating(const MultiName &key, const QQString &valu);
    void defaulted(const MultiName &key, const QQString &valu);
    void removing(const MultiName &key, const QQString &oldValu);
    void changing(const MultiName &key, const QQString &newValu, const QQString &oldValu);
    void groupChanging(const MultiName &key);

private slots:
    void insert(const MultiName &key, const QQString &valu);

public: // access
    bool contains(const MultiName &key) const;
    QQString valu(const MultiName &key, const QQString &defaultValu=Valu()) const;
    QVariant vari(const MultiName &key, const QVariant &defaultVari=QVariant()) const;
    MultiName::List keys() const { return MultiName::toList(QSettings::allKeys()); }
    QVariantMap extract() const;
    QVariantMap extract(const MultiName groupKey, const bool keepKey=false) const;
    QStringList toDebugStringList(const MultiName &groupKey=MultiName());
    static QStringList toDebugStringList(const QVariantMap &map);
    void dump(const MultiName &groupKey=MultiName());
    static void dump(const QSettings::SettingsMap &map);

public: // values
    QVariant vari(const MultiName key) { return QSettings::value(key); }
    QQString valu(const MultiName key) { return QSettings::value(key).toString(); }
    bool boolean(const MultiName &key, const bool &defaultValue=false) const;
    signed signedInt(const MultiName &key, const signed &defaultValue=0) const;
    unsigned unsignedInt(const MultiName &key, const unsigned &defaultValue=0) const;
    qreal real(const MultiName &key, const qreal &defaultValue=0) const;
    qreal realPerMille(const MultiName &key, const signed &defaultValue=0) const;
    QString string(const MultiName &key, const QString &defaultValu=QString()) const;
    QQSize size(const MultiName &key, const QQSize &defaultValu=QQSize()) const;
    static qreal perMille(const signed sValue, bool unitBound=true);

    /*
        Rational rational(const QString &key, const Rational &defaultValue=Rational(0)) const;
        Map extract(const QString groupKey, const bool keepKey=false) const;
        void import(const Map &keyValueStringMap);
        void operator += (const Map &keyValueStringMap);
        void dump() const;
    */

private:
};

