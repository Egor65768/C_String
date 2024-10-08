#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  int sizestr = s21_strlen(str);
  for (int i = sizestr - 1; i >= 0; i = i - 1) {
    if (str[i] == c) {
      res = (str + i);
      i = -1;
    }
  }
  if (c == '\0') {
    res = str + sizestr;
  }
  return (char *)res;
}
