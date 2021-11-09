# file: {torc repo}./src/apps/cons/BuildAppBoss.pri

TEMPLATE = subdirs

SUBDIRS += \
        toBase \
        toCore \
        toGui \
        toWidgets \
        toExe \
        AppBoss \

toBase.subdir           = libs/toBase
toCore.subdir           = libs/toCore
toGui.subdir            = libs/toGui
toWidgets.subdir        = libs/toWidgets
toExe.subdir            = libs/toExe
AppBoss.subdir          = apps/desktop/AppBoss

toBase.depends          =
toCore.depends          =                                       toBase
toGui.depends           =                               toCore  toBase
toWidgets.depends       =                               toCore  toBase
toExe.depends           =                               toCore  toBase
SqlCon.depends          =   toExe   toWidgets   toGui   toCore  toBase

