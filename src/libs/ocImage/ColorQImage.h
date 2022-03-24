#pragma once

#include <QQFileInfo>
#include <QImage>

#include <QMetaType>

class ColorQImage : public QImage
{
public:
    ColorQImage(const QString &fileName, const char *format=nullptr);
    ColorQImage(const QQFileInfo & fi);
    ColorQImage(const QImage & other);

public:
    QImage set(const QQFileInfo & fi);
    QImage set(const QByteArray & bytes);
    QImage set(const QImage & other);


public: // QMetaType
    ColorQImage() = default;
    ~ColorQImage() = default;
    ColorQImage(const ColorQImage &other) = default;
    ColorQImage &operator = (const ColorQImage &other) = default;
};

Q_DECLARE_METATYPE(ColorQImage);
