# file: {OttoCODE}./src/BuildAppBoss.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocType \
        ocLog \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocIO \
        ocExe \
        AppBoss \

ocBase.subdir           = libs/ocBase
ocType.subdir           = libs/ocType
ocLog.subdir            = libs/ocLog
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocIO.subdir             = libs/ocIO
ocExe.subdir            = libs/ocExe
AppBoss.subdir          = desktop/AppBoss

ocBase.depends          =
ocType.depends          =                                                       ocBase
ocLog.depends           =                                                       ocBase
ocqCore.depends         =                               ocType                  ocBase
ocqGui.depends          =                      ocqCore  ocType                  ocBase
ocqWidgets.depends      =               ocqGui ocqCore  ocType                  ocBase
ocIO.depends            =                                                       ocBase
ocExe.depends           =                                                       ocBase
AppBoss.depends         =   ocqWidgets  ocqGui ocqCore  ocType          ocLog   ocBase

