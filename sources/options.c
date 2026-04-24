#include "options.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fatal.h"

void wcx_options__help(const char *const prog) {
  puts("wcx " WCX_VERSION);
  puts("a rewrite of wc in pure c99");
  puts("created by sarkar-segfault, licensed under GPL-3.0-or-later");

  printf("\n%s [flags] <input>\n", prog);
  puts("    input\n\tpath to a file to process");
  puts("    -h, --help\n\tprints this message and exits");
  puts("    -l, --lines\n\tprints the number of lines in the file");
  puts("    -w, --words\n\tprints the number of words in the file");
  puts("    -m, --chars\n\tprints the number of chars in the file");
  puts("    -c, --bytes\n\tprints the number of bytes in the file");

  exit(0);
}

const wcx_options wcx_options_parse(const char *const *argv) {
  const char *const prog = argv[0];
  if (!prog) FATAL("expected program name as first argument");

  wcx_options options = {0};

  for (const char *const *arg = argv + 1; *arg; ++arg) {
    if (!strcmp(*arg, "-h") || !strcmp(*arg, "--help"))
      wcx_options__help(prog);

    else if (!strcmp(*arg, "-l") || !strcmp(*arg, "--lines"))
      options.lines = !options.lines;

    else if (!strcmp(*arg, "-w") || !strcmp(*arg, "--words"))
      options.words = !options.words;

    else if (!strcmp(*arg, "-m") || !strcmp(*arg, "--chars"))
      options.chars = !options.chars;

    else if (!strcmp(*arg, "-c") || !strcmp(*arg, "--bytes"))
      options.bytes = !options.bytes;

    else {
      options.file = *arg;
    }
  }

  if (!options.lines && !options.words && !options.chars && !options.bytes)
    options.lines = options.words = options.bytes = true;

  return options;
}
