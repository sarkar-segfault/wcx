#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "count.h"
#include "fatal.h"
#include "options.h"

int main(const int _, const char *const *argv) {
  const wcx_options options = wcx_options_parse(argv);

  FILE *const fp = options.file ? fopen(options.file, "rb") : stdin;
  if (!fp) FATALF("failed to obtain file %s", options.file ? options.file : "stdin");

  size_t cap = 1024;
  size_t len = 0;

  char *data = malloc(cap);
  if (!data) FATAL("failed to allocate memory");

  int ch = 0;

  while ((ch = fgetc(fp)) != EOF) {
    if (len >= cap) {
      cap *= 2;
      char *tmp = realloc(data, cap);
      if (!tmp) {
        free(data);
        FATAL("failed to reallocate memory");
      }
      data = tmp;
    }

    data[len++] = (char)ch;
  }

  printf("File         %s\n", options.file ? options.file : "stdin");

  if (options.lines) printf("Lines        %zu\n", wcx_count_lines(data, len));

  if (options.words) printf("Words        %zu\n", wcx_count_words(data, len));

  if (options.chars) printf("Chars        %zu\n", wcx_count_chars(data, len));

  if (options.bytes) printf("Bytes        %zu\n", len);

  free(data);
  return 0;
}
