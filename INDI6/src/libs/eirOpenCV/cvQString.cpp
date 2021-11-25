#include "cvQString.h"

#include <eirXfr/Debug.h>

cvQString::cvQString(const cvString &other) : QString(other.data()) {;}
