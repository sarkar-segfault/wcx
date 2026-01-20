#ifndef WCX_OPTIONS_H
#define WCX_OPTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "fatal.h"

typedef struct wcx_options {
  const char *files[256];
  bool lines;
  bool words;
  bool chars;
  bool bytes;
} wcx_options;

void wcx_options__help(const char *const prog) {
  puts("wcx " WCX_VERSION);
  puts(WCX_DESCRIPTION);
  puts("created by sarkar-segfault, licensed under GPL-3.0-or-later");

  printf("\n%s [flags] <files>\n", prog);
  puts("    files\n\ta list of 1 to 64 files to process");
  puts("    -h, --help\n\tprints this message and exits");
  puts("    -l, --lines\n\tprints the number of lines in the files");
  puts("    -w, --words\n\tprints the number of words in the files");
  puts("    -c, --chars\n\tprints the number of chars in the files");
  puts("    -b, --bytes\n\tprints the number of bytes in the files");
  
  exit(0);
}

const wcx_options wcx_options_parse(const char *const *argv) {
  const char *const prog = argv[0];
  if (prog == NULL) FATAL("expected program name as first argument");

  wcx_options options = {0};
  uint8_t idx = 0;

  for (const char *const *arg = argv + 1; *arg != NULL; ++arg) {
    if (!strcmp(*arg, "-h") || !strcmp(*arg, "--help"))
      wcx_options__help(prog);
    
    else if (!strcmp(*arg, "-l") || !strcmp(*arg, "--lines"))
      options.lines = !options.lines;

    else if (!strcmp(*arg, "-w") || !strcmp(*arg, "--words"))
      options.words = !options.words;

    else if (!strcmp(*arg, "-c") || !strcmp(*arg, "--chars"))
      options.chars = !options.chars;

    else if (!strcmp(*arg, "-b") || !strcmp(*arg, "--bytes"))
      options.bytes = !options.bytes;

    else {
      options.files[idx] = *arg;
      ++idx;
    }
  }

  if (!options.lines && !options.words && !options.chars && !options.bytes)
    options.lines = options.words = options.chars = options.bytes = true;

  return options;
}

#endif
