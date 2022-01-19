# file: {Template repo}./src/version.pri

message(----------------In version.pri)

TO85_VER_MAJOR = 1
TO85_VER_MINOR = 2
TO85_VER_RELEASE = 3
TO85_VER_BRANCH = 4
TO85_VER_STRING = "v1.2C+0004"
TO85_VER_TRUNKNAME = "develop"
TO85_VER_BRANCHNAME = "Template"
TO85_VER_QT = $${QT_VERSION}

windows:VERSION = 1.2.3.4
!windows:VERSION = 1.2.4
VER_MAJ = $${TO85_VER_MAJOR}
VER_MIN = $${TO85_VER_MINOR}
VER_PAT = $${TO85_VER_BRANCH}

message("Version = $${TO85_VER_STRING}+$${TO85_VER_BRANCHNAME} $${TO85_VER_TRUNKNAME}")


