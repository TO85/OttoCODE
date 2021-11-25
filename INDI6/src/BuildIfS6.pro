# file: {INDI6 repo}./src/apps/cons/BuildIfS6.pri

# EIRC_QMAKE_HOST=eagle

TEMPLATE = subdirs

SUBDIRS += \
        eirXfr \
        eirBase \
        eirType \
        eirXml \
        eirGui \
        eirWgt \
        eirData \
        eirExe \
        eirOpenCV \
        IfData \
        IfGeometry \
        IfObject \
        IfMarker \
        IfManager \
        IfSearch6 \

eirXfr.subdir           = libs/eirXfr
eirBase.subdir          = libs/eirBase
eirType.subdir          = libs/eirType
eirXml.subdir           = libs/eirXml
eirGui.subdir           = libs/eirGui
eirWgt.subdir           = libs/eirWgt
IfGeometry.subdir       = libs/IfGeometry
eirData.subdir          = libs/eirData
eirExe.subdir           = libs/eirExe
eirOpenCV.subdir        = libs/eirOpenCV
IfData.subdir           = libs/IfData
IfMarker.subdir         = libs/IfMarker
IfObject.subdir         = libs/IfObject
IfManager.subdir        = libs/IfManager
IfSearch6.subdir        = apps/cons/IfSearch6

eirBase.depends         =
eirType.depends         =                                                                                                           eirBase
eirGui.depends          =                                                                                                   eirType
eirWgt.depends          =                                                                                                   eirType
eirXml.depends          =                                                                                                   eirType
eirData.depends         =                                                                                                   eirType
eirExe.depends          =                                                                                                   eirType
eirOpenCV.depends       =                                                                           eirGui                  eirType eirBase
IfGeometry.depends      =                                                                                                   eirType
IfData.depends          =                                                   IfGeometry              eirGui                  eirType eirBase
IfObject.depends        =                       eirOpenCV           eirExe  IfGeometry              eirGui                  eirType
IfMarker.depends        =                                                   IfGeometry  IfObject    eirGui                  eirType eirBase
IfManager.depends       =               IfData                              IfGeometry  IfObject    eirGui  eirXml          eirType eirBase
IfSearch6.depends       =   IfManager   IfData  eirOpenCV IfMarker  eirExe  IfGeometry  IfObject                    eirData eirType         eirXfr
