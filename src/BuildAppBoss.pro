# file: {OttoCODE}./src/BuildAppBoss.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocExe \
        AppBoss \

ocBase.subdir           = libs/ocBase
ocqCore.subdir           = libs/ocqCore
ocqGui.subdir            = libs/ocqGui
ocqWidgets.subdir        = libs/ocqWidgets
ocExe.subdir            = libs/ocExe
AppBoss.subdir          = apps/desktop/AppBoss

toBase.depends          =
toCore.depends          =                                       ocBase
toGui.depends           =                               ocqCore  ocBase
toWidgets.depends       =                               ocqCore  ocBase
toExe.depends           =                               ocqCore  ocBase
AppBoss.depends          =   ocExe   ocqWidgets   ocqGui   ocqCore  ocBase

