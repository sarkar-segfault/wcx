#ifndef WCX__OPTIONS_H
#define WCX__OPTIONS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct wcx_options {
  const char *file;
  bool lines;
  bool words;
  bool chars;
  bool bytes;
} wcx_options;

const wcx_options wcx_options_parse(const char *const *argv);

#endif
