#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *new_dest = (char *)dest;
  const char *new_src = (const char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    new_dest[i] = new_src[i];
  }

  return dest;
}
