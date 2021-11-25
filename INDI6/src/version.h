// file: {INDI6 repo}./src/version.h

#include <eirBase/eirBase_global.h>

#define VER_MAJOR 6
#define VER_MINOR 17
#define VER_RELEASE 4
#define VER_BRANCH 0
#define VER_STRING "v6.17D"
#define VER_TRUNKNAME "develop"
#define VER_MINI  VER_RELEASE
#define VER_MICRO VER_BRANCH
#define VER_BRANCHNAME "origin"
#define VER_APPVER VER_STRING
#ifndef QT_DEBUG
#define VER_ORGNAME "EclipseIR"
#else
#define VER_ORGNAME "EclipseRD"
#endif

