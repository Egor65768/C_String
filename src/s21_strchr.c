#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *current = (c == 0) ? str + s21_strlen(str) : s21_NULL;
  int i = 0;
  int flag = 1;
  while (str[i] != '\0') {
    if (str[i] == c && flag) {
      current = str + i;
      flag = 0;
    }
    i++;
  }
  return (char *)current;
}
