#ifndef WCX_FATAL_H
#define WCX_FATAL_H

#include <stdlib.h>
#include <stdio.h>

#define FATAL(F) { puts(F); exit(1); }
#define FATALF(F, ...) { printf(F, __VA_ARGS__); exit(1); }

#endif
