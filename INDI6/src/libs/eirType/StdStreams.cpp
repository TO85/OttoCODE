#include "StdStreams.h"

#include <QtCore/QIODevice>

#include <eirXfr/Debug.h>

StdStreams::StdStreams()
{
    TRACEFN;
    mStreamList.reserve(All);
    for (int ix = 0; ix <= All; ++ix) mStreamList.append(nullptr);
    mStreamList[Inp] = nullptr;
    mStreamList[Out] = nullptr;
    mStreamList[Err] = nullptr;
}

QTextStream *StdStreams::port(const Port p) const
{
//    TRACEQFI << p << hex << mStreamList[p] << dec;
    return mStreamList[p];
}

QTextStream *StdStreams::inp()
{
    if (nullptr == port(Inp)) open(Inp);
    return port(Inp);
}

QTextStream *StdStreams::out()
{
    if (nullptr == port(Out)) open(Out);
    return port(Out);
}

QTextStream *StdStreams::err()
{
    if (nullptr == port(Err)) open(Err);
    return port(Err);
}

void StdStreams::close(const Ports p)

{
    if (false)
        ;
    else if (Inp & p)
        close(Inp);
    else if (Out & p)
        close(Out);
    else if (Err & p)
        close(Err);
    else
        AEXPECTNOT(p & ~All);
}

void StdStreams::close(const StdStreams::Port p)
{
    if (mStreamList[p])
    {
        TRACEQFI << p << QOBJNAME(mStreamList[p]->device());
        delete mStreamList[p];
    }
    mStreamList[p] = nullptr;
}

void StdStreams::flush(const Ports p)
{
    if (false)
        ;
    else if (Inp & p)
        flush(Inp);
    else if (Out & p)
        flush(Out);
    else if (Err & p)
        flush(Err);
    else
        AEXPECTNOT(p & ~All);

}

void StdStreams::flush(const StdStreams::Port p)
{
    if (mStreamList[p]) mStreamList[p]->flush();
}

bool StdStreams::open(const Ports p)
{
    bool success = true;
    close(p);
    if (false)
        ;
    else if (Inp & p)
        success &= open(Inp);
    else if (Out & p)
        success &= open(Out);
    else if (Err & p)
        success &= open(Err);
    else
        AEXPECTNOT(p & ~All);
    return success;
}
bool StdStreams::open(const StdStreams::Port p)
{
    switch (p)
    {
    case Inp:   return open(Inp, stdin);
    case Out:   return open(Out, stdout);
    case Err:   return open(Err, stderr);
    default:    return false;
    }
}

bool StdStreams::open(const StdStreams::Port p, FILE *fh)
{
    close(p);
    mStreamList[p] = new QTextStream(fh, (Inp == p) ? QIODevice::ReadOnly : QIODevice::WriteOnly);
    return mStreamList[p]->device()->isOpen();
}

bool StdStreams::open(const StdStreams::Port p, QIODevice *iod)
{
    close(p);
    mStreamList[p] = new QTextStream(iod);
    return mStreamList[p]->device()->isOpen();
}

void StdStreams::write(const QString &qs, const bool andFlush)
{
    *out() << qs;
    if (andFlush) out()->flush();
    if (forking()) qInfo() << "INFO:" << qs;
}

void StdStreams::writeLine(const QString &qs, const bool andFlush)
{
    *out() << qs;
    *out() << Qt::endl;
    if (andFlush) out()->flush();
    if (forking()) qInfo() << "INFO:" << qs;
}

void StdStreams::writeLines(const QStringList &qsl, const QString &pfx)
{
    for (auto &qs : qsl) writeLine(pfx + qs, false);
    flush(Out);
}

void StdStreams::errorLine(const QString &qs)
{
    *err() << qs << Qt::endl;
    err()->flush();
    if (forking()) qCritical() << "CRIT:" << qs;
}
