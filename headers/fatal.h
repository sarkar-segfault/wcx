#ifndef WCX__FATAL_H
#define WCX__FATAL_H

#include <stdlib.h> // IWYU pragma: keep
#include <stdio.h> // IWYU pragma: keep

#define FATAL(F) { fputs(F "\n", stderr); exit(1); }
#define FATALF(F, ...) { fprintf(stderr, F "\n", __VA_ARGS__); exit(1); }

#endif
