# {OttoCODE}./src/dest.pri

message(----------------In dest.pri)

message(OTTOCODE_BASEBINDIR = $$OTTOCODE_BASEBINDIR)
message(CTOOL = $$CTOOL)
message(OC_VER_STRING = $$OC_VER_STRING)
message(OC_VER_TRUNKNAME = $$OC_VER_TRUNKNAME)
message(OC_VER_BRANCHNAME = $$OC_VER_BRANCHNAME)

OURDEST = <base>/<ctool><qtmain>-<bld>-<ver>-<trunk>+<branch>
OURDEST = $$replace(OURDEST, <base>, $$OTTOCODE_BASEBINDIR)
OURDEST = $$replace(OURDEST, <ctool>, $$CTOOL)
OURDEST = $$replace(OURDEST, <qtmain>, $$QT_MAJOR_VERSION)
CONFIG(debug, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <bld>, dbg)
}
CONFIG(release, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <bld>, bin)
}
CONFIG(profile, debug|release|profile) {
    OURDEST = $$replace(OURDEST, <bld>, pro)
}
OURDEST = $$replace(OURDEST, <ver>, $$OC_VER_STRING)
OURDEST = $$replace(OURDEST, <trunk>, $$OC_VER_TRUNKNAME)
OURDEST = $$replace(OURDEST, <branch>, $$OC_VER_BRANCHNAME)
DESTDIR = $$OURDEST
LIBS *= -L$$OURDEST

message(OURDEST = $$OURDEST)
