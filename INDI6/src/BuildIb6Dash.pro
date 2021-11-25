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
        IfData \
        IfGeometry \
        Ib6Dash \

eirXfr.subdir           = libs/eirXfr
eirBase.subdir          = libs/eirBase
eirType.subdir          = libs/eirType
eirXml.subdir           = libs/eirXml
eirGui.subdir           = libs/eirGui
eirWgt.subdir           = libs/eirWgt
IfGeometry.subdir       = libs/IfGeometry
eirData.subdir          = libs/eirData
eirExe.subdir           = libs/eirExe
IfData.subdir           = libs/IfData
Ib6Dash.subdir          = apps/desk/Ib6Dash

eirXfr.depends          =
eirBase.depends         =
eirType.depends         =                                                   eirBase
eirGui.depends          =                                           eirType
eirWgt.depends          =                                           eirType
eirXml.depends          =                                           eirType
eirData.depends         =                                           eirType
eirExe.depends          =                                           eirType
IfGeometry.depends      =                                           eirType
IfData.depends          =   IfGeometry          eirGui              eirType eirBase
Ib6Dash.depends         =               eirExe              eirData eirType eirBase   eirXfr
