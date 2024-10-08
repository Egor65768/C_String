#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int k = s21_strlen(dest);
  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    dest[k + i] = src[i];
    dest[k + i + 1] = '\0';
  }
  return dest;
}
