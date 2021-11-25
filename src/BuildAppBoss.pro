# file: {torc repo}./src/apps/cons/BuildAppBoss.pri

TEMPLATE = subdirs

SUBDIRS += \
        toBase \
        toCore \
        toGui \
        toWidgets \
        toExe \
        eirXfr \
        eirBase \
        eirType \
#        eirXml \
        eirGui \
        eirWgt \
#        eirData \
        eirExe \
#        IfData \
#        IfGeometry \
        AppBoss \

toBase.subdir           = libs/toBase
toCore.subdir           = libs/toCore
toGui.subdir            = libs/toGui
toWidgets.subdir        = libs/toWidgets
toExe.subdir            = libs/toExe
eirXfr.subdir           = ../INDI6/src/libs/eirXfr
eirBase.subdir          = ../INDI6/src/libs/eirBase
eirType.subdir          = ../INDI6/src/libs/eirType
eirGui.subdir           = ../INDI6/src/libs/eirGui
eirWgt.subdir           = ../INDI6/src/libs/eirWgt
eirExe.subdir           = ../INDI6/src/libs/eirExe
AppBoss.subdir          = apps/desktop/AppBoss

toBase.depends          =
toCore.depends          =                                       toBase
toGui.depends           =                               toCore  toBase
toWidgets.depends       =                               toCore  toBase
toExe.depends           =                               toCore  toBase
SqlCon.depends          =   toExe   toWidgets   toGui   toCore  toBase  eirEze

eirXfr.depends          =
eirBase.depends         =
eirType.depends         =                                                   eirBase
eirGui.depends          =                                           eirType
eirWgt.depends          =                                           eirType
#eirXml.depends          =                                           eirType
#eirData.depends         =                                           eirType
eirExe.depends          =                                           eirType           eirXfr
#IfGeometry.depends      =                                           eirType
#IfData.depends          =   IfGeometry          eirGui              eirType eirBase
#Ib6Dash.depends         =               eirExe              eirData eirType eirBase   eirXfr
