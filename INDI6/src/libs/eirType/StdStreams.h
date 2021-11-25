#pragma once
#include "eirType.h"

#include <QFlags>
#include <QString>
#include <QList>

class QIODevice;
class QTextStream;

class EIRTYPE_EXPORT StdStreams
{
public:
    enum Port { None = 0, Inp = 1, Out = 2, Err = 4, All = 7 };
    Q_DECLARE_FLAGS(Ports, Port);

public:
    StdStreams();
    QTextStream * port(const Port p) const;
    QTextStream * inp();
    QTextStream * out();
    QTextStream * err();

    void close(const Ports p=All);
    void close(const Port p);
    void flush(const Ports p=All);
    void flush(const Port p);
    bool open(const Ports p=All);
    bool open(const Port p);
    bool open(const Port p, FILE * fh);
    bool open(const Port p, QIODevice * iod);

    void forkTroll(const bool fork=true) { mForkTroll = fork; }
    bool forking() const { return mForkTroll; }

    void write(const QString &qs, const bool andFlush=true);
    void writeLine(const QString &qs, const bool andFlush=true);
    void writeLines(const QStringList &qsl, const QString &pfx=QString());
    void errorLine(const QString &qs);

private:
    bool mForkTroll=true;
    QList<QTextStream *> mStreamList;
};

