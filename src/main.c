#include <stdint.h>
#include "options.h"

int main(const int _, const char *const *argv) {
  const wcx_options options = wcx_options_parse(argv);

  for (uint8_t idx = 0; idx < 255; ++idx) {
    printf("%s\n", options.files[idx]);
  }
  
  return 0;
}
