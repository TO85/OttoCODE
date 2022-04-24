#pragma once

#include <QImage>

#include <QMetaType>

#include <QQFileInfo>

class FloatQImage : public QImage
{
public:
    FloatQImage(const QString &fileName, const char *format=nullptr);
    FloatQImage(const QQFileInfo & fi);
    FloatQImage(const QImage & other);

public:
    QImage set(const QQFileInfo & fi);
    QImage set(const QByteArray & bytes);
    QImage set(const QImage & other);

private:
    FloatQImage it() const { return *this; }
    FloatQImage & it() { return *this; }


public: // QMetaType
    FloatQImage() = default;
    ~FloatQImage() = default;
    FloatQImage(const FloatQImage &other) = default;
    FloatQImage &operator = (const FloatQImage &other) = default;
};

Q_DECLARE_METATYPE(FloatQImage);

