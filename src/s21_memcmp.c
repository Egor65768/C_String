#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *new_str1 = (const char *)str1;
  const char *new_str2 = (const char *)str2;
  int output = 0;
  int flag = 1;
  for (s21_size_t i = 0; i < n; i++) {
    if ((new_str1[i] != new_str2[i]) && flag) {
      output = new_str1[i] - new_str2[i];
      flag = 0;
    }
  }
  return output;
}
