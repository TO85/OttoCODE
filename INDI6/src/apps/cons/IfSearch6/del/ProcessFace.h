#pragma once

#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtGui/QImage>

#include <eirVar/VariableMap.h>

class ProcessFace
{
public:
    ProcessFace(const VariableMap &initMap=VariableMap(),
                const VariableMap &configMap=VariableMap());
    void initialize(const VariableMap &initMap=VariableMap());
    void configure(const VariableMap &configMap=VariableMap());
    bool load(const QString &filePathName);
    bool load(const QDir &dir, const QString &fileName);
    bool load();
    void process(const QImage &faceImage, const VariableMap &imageConfigMap);
};

