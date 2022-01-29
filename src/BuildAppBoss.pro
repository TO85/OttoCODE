# file: {OttoCODE}./src/BuildAppBoss.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocLog \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocExe \
        AppBoss \

ocBase.subdir           = libs/ocBase
ocLog.subdir            = libs/ocLog
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocExe.subdir            = libs/ocExe
AppBoss.subdir          = apps/desktop/AppBoss

toBase.depends          =
ocLog.depends           =                                       ocBase
toCore.depends          =
toGui.depends           =                                       ocBase
toWidgets.depends       =                        ocqGui         ocBase
toExe.depends           =
AppBoss.depends         =           ocqWidgets   ocqGui ocqCore ocBase

