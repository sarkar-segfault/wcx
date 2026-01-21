#ifndef WCX__COUNT_H
#define WCX__COUNT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

const size_t wcx_count_chars(const char *const path, const size_t size);
const size_t wcx_count_lines(const char *const path, const size_t size);
const size_t wcx_count_words(const char *const path, const size_t size);

#endif
