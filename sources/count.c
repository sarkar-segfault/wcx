#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "count.h"

const size_t wcx_count_chars(const char *data, size_t size) {
  size_t chars = 0;

  for (size_t i = 0; i < size; i++) {
    unsigned char byte = (unsigned char)data[i];
    if ((byte & 0b11000000) != 0b10000000) {
      chars++;
    }
  }

    return chars;
}

const size_t wcx_count_lines(const char *const data, const size_t size) {
  size_t lines = 0;
  for (size_t i = 0; i < size; ++i) {
    if (data[i] == '\n') lines++;
  }
  return lines;
}

const size_t wcx_count_words(const char *const data, const size_t size) {
  size_t words = 0;
  bool word = false;

  for (size_t i = 0; i < size; ++i) {
    if (isspace((unsigned char)data[i])) {
      word = false;
    } else if (!word) {
      word = true;
      words++;
    }
  }

  return words;
}
