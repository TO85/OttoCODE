#pragma once

#include <QFile>

#include <QQFileInfo>

class QQFile : public QFile
{
    Q_OBJECT
public:
    explicit QQFile(QObject *parent = nullptr);

public: // static
    static QByteArray readFile(const QQFileInfo &fileInfo);
};

