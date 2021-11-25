# file: {INDI6 repo}./src/dest.pri

message(----------------In dest.pri)

message(EIRC_BASEDESTDIR = $${EIRC_BASEDESTDOR})
message(CTOOL = $$CTOOL)
message(EIRC_VER_STRING = $$EIRC_VER_STRING)
message(EIRC_VER_TRUNKNAME = $$EIRC_VER_TRUNKNAME)
message(EIRC_VER_BRANCHNAME = $$EIRC_VER_BRANCHNAME)

OURDEST = <base>/<ctool>-<dbg>-<ver>-<trunk>+<branch>
OURDEST = $$replace(OURDEST, <base>, $${EIRC_BASEDESTDIR})
OURDEST = $$replace(OURDEST, <ctool>, $$CTOOL)
CONFIG(debug, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <dbg>, dbg)
}
CONFIG(release, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <dbg>, bin)
}
CONFIG(profile, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <dbg>, pro)
}
OURDEST = $$replace(OURDEST, <ver>, $$EIRC_VER_STRING)
OURDEST = $$replace(OURDEST, <trunk>, $$EIRC_VER_TRUNKNAME)
OURDEST = $$replace(OURDEST, <branch>, $$EIRC_VER_BRANCHNAME)
DESTDIR = $$OURDEST
LIBS *= -L$$OURDEST

message(OURDEST = $$OURDEST)
