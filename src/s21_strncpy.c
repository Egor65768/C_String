#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int check = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (src[i] != '\0' && !check) {
      dest[i] = src[i];
    } else if (src[i] == '\0' && !check) {
      dest[i] = src[i];
      check = 1;
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}
