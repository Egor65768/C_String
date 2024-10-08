#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int count = n / sizeof(char);
  int flag = 0;
  const char *res = str;
  for (int i = 0; i < count; i++) {
    if (*res == c) {
      i = count;
      flag = 1;
    }
    if (i != count) {
      res++;
    }
  }
  if (flag == 0) {
    res = s21_NULL;
  }
  return (void *)res;
}
