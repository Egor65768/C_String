#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t s21_len = s21_strlen(str);
    res = (char *)malloc(sizeof(char) * (s21_len + 1));
    if (res) {
      for (s21_size_t i = 0; i < s21_len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          res[i] = str[i] + ('a' - 'A');
        } else {
          res[i] = str[i];
        }
      }
      res[s21_len] = '\0';
    }
  }
  return res;
}